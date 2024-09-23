Ý tưởng:
- Cứ mỗi khối rubik cần kiểm tra xem có tòa tháp nào có thể cho nó chồng lên hay không. 
  + Nếu không thì tạo 1 tòa tháp mới có đáy là chính nó. 
  + Nếu có thì thay đỉnh của tòa tháp tìm được bằng khối rubik đó
Ví dụ:
Input:
5
3 8 2 1 5
Output:
2
Giải:
Ban đầu ta chưa có tòa tháp nào nên khối rubik đầu tiên sẽ là tòa 1: 3
Tiếp đến khối rubik 8 thì ta chỉ có 1 tòa 3 tuy nhiên 8 > 3 nên ta không chồng 8 lên được nên phải tạo thêm 1 tòa tháp 8: 3 8
Tiếp theo đến khối 2 thì ta tìm được tòa 3 có 3 > 2 nên ta chồng 2 lên 3 ta được:
2
3 8 (ở đây có thể thay thành 2 8, do ví dụ cho trực quan)
Tiếp đến khối 1 thì ta tìm được tòa 2 > 1 nên thực hiện chồng lên ta được:
1
2
3 8 (hay 1 8)
cuối cùng là khối 5 ta tìm được tòa 8 > 5 nên thực hiện chồng thành:
1
2 5
3 8 (hay 1 5)
Vậy ta xây được ít nhất 2 tòa tháp
Độ phức tạp: O(nlog(n))
Code:
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MAXN = 2e5 + 1;
int n;
int k[MAXN];
vector<int> v;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    FOR(i, 0, n - 1) {
        cin >> k[i];
    }
    FOR(i, 0, n - 1) {
        auto it = upper_bound(all(v), k[i]);
        if (it == end(v)) v.pb(k[i]);
        else {
            *it = k[i];
        }
    }
    cout << v.size();
    return 0;
}
