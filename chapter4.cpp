#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memo;

int func(int i, int w, const vector<int>& a) {
    // ベースケース
    if (i == 0) {
        if (w == 0) {
            return memo.at(0).at(0) = 1;
        } else {
            return memo.at(0).at(0) = 0;
        }
    }

    // メモ化変数をチェックし、計算済みなら返す。
    if (memo.at(i).at(w) != -1) {
        return memo.at(i).at(w);
    } else if (func(i - 1, w, a)) {
        return memo.at(i).at(w) = 1;
    } else if (func(i - 1, w - a[i - 1], a)) {
        return memo.at(i).at(w) = 1;
    }

    // どちらもfalseの場合は、false
    return 0;
}

int main() {
    // 入力
    int N, W;
    cin >> N >> W;

    vector<int> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }

    // メモ化変数を初期化
    memo.assign(N + 1, vector<int>(W + 1, -1));

    // 再帰的に解く
    if (func(N, W, a)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}