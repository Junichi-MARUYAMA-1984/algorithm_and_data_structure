#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int N, v;
    cin >> N >> v;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // 線型探索
    int found_id = -1; // 初期値は-1などとあり得ない値に。
    for (int i = 0; i < N; ++i) {
        if (a[i] == v) {
            found_id = i; // 見つかったら添字を記録。
            break; // ループを抜ける。
        }
    }

    // 結果出力 (-1のときは見つからなかったことを意味する)
    cout << found_id << endl;
}