#include <iostream>
#include <vector>
using namespace std;

// 配列aの区間 [left, right) をソートする
// [left, right)は、left, left + 1, ..., right - 1番目を表す
void QuickSort(vector<int> &a, int left, int right) {
    if (right - left <= 1) return;

    int pivot_index = (left + right) / 2; // ここではpivotを中心とする。（別に中心でなくてもよい。選び方は適当）
    int pivot = a[pivot_index];
    swap(a[pivot_index], a[right - 1]); // pivotと右端をswap

    int i = left; // iは左詰めされたpivot未満要素の右端を表す
    for (int j = left; j < right - 1; ++j) {
        if (a[j] < pivot) {
            swap(a[i++], a[j]);
        }
    }
    swap(a[i], a[right - 1]); // 最後にpivotを適切な位置に挿入する

    // 再帰的に解く
    QuickSort(a, left, i); // 左半分(pivot未満)
    QuickSort(a, i + 1, right); // 右半分(pivot以上)
}

int main() {
    // 入力
    int N; // 要素数
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // クイックソート
    QuickSort(a, 0, N);

    // 結果出力
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << a[i] << endl;
    }
}