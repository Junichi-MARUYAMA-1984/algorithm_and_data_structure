#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;

int tribo(int N) {
    // ベースケース
    if (N == 0) {
        return 0;
    } else if (N == 1) {
        return 0;
    } else if (N == 2) {
        return 1;
    }

    // メモ化変数に計算結果がある場合はそれを返す。
    if (memo[N] != -1) {
        return memo[N];
    }

    // 再帰呼び出し
    return memo[N] = tribo(N - 1) + tribo(N - 2) + tribo(N - 3);
}

int main() {
    // 求める項目を入力
    int num;
    cin >> num;

    // メモ化変数を初期化
    memo.assign(num, -1);

    cout << tribo(num - 1) << endl;
}