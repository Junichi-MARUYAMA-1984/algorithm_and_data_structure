#include <iostream>
#include <vector>
using namespace std;

// 配列aをソートする
void InsertionSort(vector<int> &a) {
    int N = (int)a.size();
    for (int i = 1; i < N; ++i) {
        int v = a[i]; // 挿入したい値

        // vを挿入する適切な場所jを探す
        int j = i;
        for (; j > 0; --j) {
            if (a[j - 1] > v) { // vより大きいものは1つ後ろにずらす
                a[j] = a[j - 1];
            }
            else break; // v以下になったら止める
        }
        a[j] = v; // 最後にj番目にvを持ってくる
    }
}

int main() {
    //　入力
    int N; // 要素数
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // 挿入ソート
    InsertionSort(a);
}