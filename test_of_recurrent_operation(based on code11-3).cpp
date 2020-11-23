#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par, siz;

    // 初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    // 根を求める
    int root(int x) {
        if (par[x] == -1) {
            cout << "root(" << x << ") = " << x << endl;
            cout << endl;
            return x; // xが根の場合はxを返す
        } else {
            cout << "root(" << x << "): par[" << x << "] = root(par[" << x << "]) (== root(" << par[x] << ") <-- the return value of root(" << x << "))" << endl;
            return par[x] = root(par[x]);
        }
    }

    // xとyが同じグループに属するかどうか（根が一致するかどうか）
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // xを含むグループとyを含むグループとを併合する
    bool unite(int x, int y) {
        // xとyをそれぞれ根まで移動する
        x = root(x);
        y = root(y);

        // すでに同じグループの時は何もしない
        if (x == y) return false;

        // union by size (y側のサイズが小さくなるように)
        if (siz[x] < siz[y]) swap(x, y);

        // yをxの子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // xを含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    UnionFind uf(7); // {0}, {1}, {2}, {3}, {4}, {5}, {6}

    uf.unite(1, 2); // {0}, {1, 2}, {3}, {4}, {5}, {6}
    uf.unite(2, 3); // {0}, {1, 2, 3}, {4}, {5}, {6}
    uf.unite(5, 6); // {0}, {1, 2, 3}, {4}, {5, 6}
    cout << boolalpha; // bool値の出力を"true", "false"に変える
    cout << uf.issame(1, 3) << endl; // true
    cout << uf.issame(2, 5) << endl; // fale

    uf.unite(1, 6); // {0}, {1, 2, 3, 5, 6}, {4}
    cout << uf.issame(2, 6) << endl; // true
}