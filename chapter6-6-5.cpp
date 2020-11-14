#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60; // 十分大きい値を1つ決める。

int main() {
    // 入力
    int N;
    cin >> N;

    vector<long long> h(N), s(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i] >> s[i];
    }

    // 二分探索
    long long left = 0, right = INF;
    while (right - left > 1) {
        long long mid = left + (right - left) / 2;

        // 判定
        bool ok = true;
        vector<long long> t(N, 0); // 各風船を割るまでの時間制限
        for (int i = 0; i < N; ++i) {
            // そもそもmidが初期高度より低かったらfalse
            if (mid < h[i]) {
                ok = false;
            } else {
                t[i] = (mid - h[i]) / s[i];
            }
        }

        // 時間が差し迫っている順にソート
        sort(t.begin(), t.end());
        for (int i = 0; i < N; ++i) {
            if (t[i] < i) { // 一秒に一個割っていくので、i番目に割るべき風船の時間制限t[i]秒がi秒よりも短いと時間内に割ることができない。
                ok = false; // 時間切れ発生
            }
        }

        if (ok) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;
}