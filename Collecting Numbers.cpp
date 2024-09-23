Ý tưởng:
- Lưu vị trí của các phần tử lại rồi sắp xếp tăng dần
- Duyệt qua các phần tử:
  + thêm 1 vòng
  + Nếu phần tử sau có chỉ số lớn hơn phần tử trước nó thì phần tử đó được duyệt đồng thời tăng chỉ số lên để kiểm ta phần tử kế tiếp
  + Ngược lại nếu chỉ số nhỏ hơn thì trả con trỏ về vị trí đó và quay trở lại bước 1
Ví dụ:
Input:
5
4 2 1 5 3
Ouput:
3
Giải:
Lưu lại chỉ số từng phần tử và sắp xếp, khi đó ta được dãy
Value: 1 2 3 4 5
Pos:   3 2 5 1 4
Vòng thứ 1:
ta chỉ duyệt được số 1 vì vị trí của 2 bé hơn vị trí của 1
Vòng thứ 2:
ta duyệt được 2 và 3 vì chỉ số của 4 bé hơn chỉ số của 3
Vòng thứ 3 ta duyệt được 4 và 5, tại 5 con trỏ trỏ đến cuối nên dừng vòng lặp và in ra kết quả ta được 3 vòng
Độ phức tạp: O(nlog(n))
Code:
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int MAXN = 2e5 + 1;
int n;
int a[MAXN];
unordered_map<int, int> pos;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    FOR(i, 0, n - 1) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    sort(a, a + n);
    int count = 0, i = 0;
    while (i < n) {
        count++;
        int j = i + 1;
        while (j < n && pos[a[j]] > pos[a[j-1]]) {
            j++;
        }
        i = j;
    }
    cout << count;
    return 0;
}
