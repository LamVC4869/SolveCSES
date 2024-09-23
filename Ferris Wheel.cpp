ý tưởng giải bài tập: sắp xếp + kỹ thuật 2 con trỏ
- nếu thuyền không có ai thì thêm bạn nặng nhất(bạn A) trước, lúc này thuyền chỉ có thể chứa thêm 1 bạn
- nếu bạn trước bạn A(bạn B) có cân nặng đủ để lên thuyền thì ta sẽ tăng thêm 1 chiếc thuyền.
- nếu bạn B quá nặng so với thuyền thì chuyển lên đầu hàng. Cho bạn đầu hàng lên thuyền nếu bạn đó đủ hoặc dưới khối lượng thuyền có thể chứa (lúc này tăng số thuyền thêm 1 vì đã đủ 2 bạn). Nếu bạn vẫn quá nặng so với thuyền thì ta tăng thêm số thuyền là 1 và quay trở lại bước 1.
- thực hiện tuần tự như vậy cho đến khi không còn bạn nào không lên thuyền.
- Độ phức tạp: O(nlog(n))
Ví dụ:
Input:
8 22
6 10 7 6 9 10 7 7
Output:
4
Giải:
- Đầu tiên sắp xếp dãy tăng dần
=> P = 6, 6, 7, 7, 7, 9, 10, 10
lúc này ta có thuyền chịu được trọng tải tối đa là 22
- Bắt đầu với bạn cuối cùng ta có trọng tải còn lại là 12, tiếp tục đến bạn phía trước thì thuyền còn chịu được 2 (22 - 10 - 10) nhưng do đã đủ 2 bạn nên ta đếm được 1 chiếc thuyền.
- Tiếp theo với chiếc thứ 2 ta làm tương tự thì thuyền còn chịu được (22 - 9 - 7 = 6) nhưng do đã đủ 2 bạn nên ta đếm được thêm 1 chiếc thuyền.
- Tương tự với chiếc thứ 3 ta được 2 bạn có cân nặng là 7 và 7 (chiếc thứ 3)
- Cuối cùng là 2 bạn có cân nặng là 6 và 6, lúc này con trỏ cuối nhỏ hơn con trỏ đầu nên dừng chương trình và cộng thêm chiếc thuyền cuối đó ta được 4 chiếc thuyền cho toàn bộ bạn nhỏ.
Code:
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int MAXN = 2e5 + 1;
int n, x;
int p[MAXN];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> x;
    FOR(i, 0, n - 1) {
        cin >> p[i];
    }
    sort(p, p + n);
    int count = 0, temp = x, k = 2;
    //Dùng kỹ thuật 2 con trỏ
    int i = 0, j = n - 1;
    while (i <= j) {
        if (!k) {
            temp = x;
            count++;
            k = 2;
        }
        if (p[j] <= temp) {
            temp -= p[j--];
            k--;
        }
        else {
            while (i <= j) {
                //nếu đủ 2 người thì chuyển sang thuyền khác
                if (!k) {
                    break;
                }
                if (p[i] > temp) {
                    k = 2;
                    count++;
                    temp = x;
                    break;
                }
                temp -= p[i++];
                k--;
            }    
        }
    }
    // thêm 1 chiếc thuyền cuối
    cout << count + 1;
    return 0;
}
