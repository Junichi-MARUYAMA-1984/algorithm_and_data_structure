#include <iostream>
#include <vector>
using namespace std;

// 無限大を表す値
const long long INF = 1LL << 60;

int main() {
    // 頂点数、辺の数
    int N, M;
    cin >> N >> M;

    // dp配列。INFで初期化。
    vector<vector<long long>> dp(N, vector<long long>(N, INF));

    // dp初期条件
    for (int e = 0; e < M; ++e) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }
    for (int v = 0; v < N; ++v) dp[v][v] = 0;

    // dp遷移（フロイド・ワーシャル法）
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    // 結果出力
    // もしdp[v][v] < 0なら負閉路が存在する。
    bool exist_negative_cycle = false;
    for (int v = 0; v < N; ++v) {
        if(dp[v][v] < 0) exist_negative_cycle = true;
    }
    if (exist_negative_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j) cout << " ";
                if (dp[i][j] < INF / 2) cout << dp[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }
}