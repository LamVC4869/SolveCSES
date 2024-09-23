ý tưởng:
- Ghi nhận lại những thời điểm khách đến và khách đi, nếu đến thì tại thời điểm đó cộng thêm 1 khách, ngược lại thì trừ đi 1.
- Tạo 1 dãy tăng dần tồn tại từ thời điểm sớm nhất đến thời điểm chậm nhất, cập nhật số lượng khách của từng thời điểm và trả về số khách nhiều nhất có thể trong 1 thời điểm.
Ví dụ:
Input:
3
5 8
2 4
3 9
Output:
2
Giải:
tại thời điểm 5, 2 và 3 ta tăng số khách thêm 1
tại thời điểm 8, 4 và 9 ta giảm số khách đi 1
duyệt từ 2 tới 9 ta được số khách của những thời điểm tồn tại là:
số khách:  1 2 1 2 1 0
thời điểm: 2 3 4 5 8 9
vậy kết quả chính là giá trị lớn nhất của số khách = 2
Độ phức tạp: O(nlog(n))
Code:
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
using namespace std;

const int MAXN = 2e5 + 1;
int n, k = 0;
vector<int> temp;
map<int, int> mp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    FOR(i, 0, n - 1) {
        int a, b; cin >> a >> b;
        mp[a]++;
        mp[b]--;
    }
    for (auto it : mp) {
        k += it.se;
        temp.pb(k);
    }
    cout << *max_element(all(temp));
    return 0;
}
