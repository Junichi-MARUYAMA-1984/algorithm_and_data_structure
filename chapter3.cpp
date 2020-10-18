#include <iostream>
#include <vector>
using namespace std;

const int INF = 200000000; // 十分大きな値にする。

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

    // 線型探索
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // 和がK未満の時は捨てる。
            if (a[i] + b[j] < K) {
                continue;
            }

            // 最小値を更新する
            if (a[i] + b[j] < min_value) {
                min_value = a[i] + b[j];
            }
        }
    }

    // 結果出力
    cout << min_value << endl;
}