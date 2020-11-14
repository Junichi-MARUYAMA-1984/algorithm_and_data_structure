#include <iostream>
#include <vector>
#include <algorithm> // sort()やlower_bound()に必要。
using namespace std;
const int INF = 20000000; // 十分大きな値。

int main() {
    // 入力を受け取る
    int N, K;
    cin >> N >> K;
    
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }

    // 暫定最小値を格納する変数
    int min_value = INF;

    // bをソート。
    sort(b.begin(), b.end());

    // aを固定して解く。
    for (int i = 0; i < N; ++i) {
        // bの中でK - a[i]以上の範囲で最小値を示すイテレータ
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

        // イテレータの示す値を取り出す。
        int val = *iter;

        // min_valueと比較する。
        if (a[i] < min_value) {
            min_value = a[i] + val;
        }
    }
    cout << min_value << endl;
}