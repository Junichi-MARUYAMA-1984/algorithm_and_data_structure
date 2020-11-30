#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

// トポロジカルソートする
vector<bool> seen;
vector<int> order; // トポロジカルソート順を表す。
void rec(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // すでに訪問済みならば探索しない。
        rec(G, next_v);
    }

    // v-out（頂点vについて再帰関数を抜けたタイミング）を記録する
    order.push_back(v);
}

int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ情報の受け取り（有向グラフを想定）
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 探索
    seen.assign(N, false); // 初期状態では全頂点が未訪問
    order.clear(); // トポロジカルソート結果をクリア。
    for (int v = 0; v < N; ++v) {
        if (seen[v]) continue; // 既に訪問済みならば探索しない。
        rec(G, v);
    }
    reverse(order.begin(), order.end()); // 逆順にすることでトポロジカルソートが完成する。

    // 結果出力
    for (auto v : order) cout << v << " -> ";
    cout << endl;
}