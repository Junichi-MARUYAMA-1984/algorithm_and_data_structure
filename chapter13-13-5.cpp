#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

// 二部グラフ判定
vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
    color[v] = cur;
    for (auto next_v : G[v]) {
        // 隣接頂点がすでに色確定していた場合
        if (color[next_v] != -1) {
            // 同じ色が隣接した場合は二部グラフではない
            if (color[next_v] == cur) return false;

            // 色が確定していた場合には探索しない
            continue;
        }

        // 隣接頂点の色として「現在頂点の色と反対の色」を割り当てて、再帰的に探索。
        // falseが返ってきたら、falseを返す。
        if (!dfs(G, next_v, 1 - cur)) return false;
    }
    return true;
}

int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ入力受け取り（無向グラフを想定）
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    color.assign(N, -1);
    bool is_bipartite = true;
    for (int v = 0; v < N; ++v) {
        if (color[v] != -1) continue; // vが訪問済みの時は探索しない
        if (!dfs(G, v)) is_bipartite = false;
    }

    // 結果出力
    if (is_bipartite) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}