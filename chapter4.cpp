#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> memo;

bool func(int i, int w, const vector<int>& a) {
    // ベースケース
    if (i == 0) {
        if (w == 0) {
            return memo.at(0).at(0) = true;
        } else {
            return false;
        }
    }

    // a[i - 1]を選ばない場合
    if (memo.at(i - 1).at(w)) {
        return memo.at(i).at(w) = true;
    } else if (func(i - 1, w, a)) {
        return memo.at(i).at(w) = true;
    }

    // a[i - 1]を選ぶ場合
    if (w - a[i - 1] >= 0) {
        if (memo.at(i - 1).at(w - a[i - 1])) {
            return memo.at(i).at(w) = true;
        } else if (func(i - 1, w - a[i - 1], a)) {
            return memo.at(i).at(w) = true;
        }
    }

    // どちらもfalseの場合は、false
    return false;
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
    memo.assign(N + 1, vector<bool>(W + 1, false));

    // 再帰的に解く
    if (func(N, W, a)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}