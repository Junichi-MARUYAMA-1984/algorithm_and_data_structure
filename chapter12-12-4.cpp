#include <iostream>
#include <vector>
using namespace std;

// i番目の頂点を根とする部分木について、ヒープ条件を満たすようにする。
// aのうち0番目からN - 1番目までの部分a[0:N]についてのみ考える。
void Heapify(vector<int> &a, int i, int N) {
    int child1 = i * 2 + 1; // 左の子供
    if (child1 >= N) return; // 子供がないときは終了

    // 子供同士を比較
    if (child1 + 1 < N && a[child1 + 1] > a[child1]) ++child1;

    if (a[child1] <= a[i]) return; // 逆転がなかったら終了

    //swap
    swap(a[i], a[child1]);

    // 再帰的に
    Heapify(a, child1, N);
}

// 配列aをソートする
void HeapSort(vector<int> &a) {
    int N = (int)a.size();

    // ステップ1: a全体をヒープにするフェイズ
    for (int i = N / 2 - 1; i >= 0; --i) {
        Heapify(a, i, N);
    }

    // ステップ2: ヒープから一つずつ最大値をpopするフェイズ
    for (int i = N - 1; i > 0; --i) {
        swap(a[0], a[i]); // ヒープの最大値を左詰め
        Heapify(a, 0, i); // ヒープサイズはiに
    }
}

int main() {
    // 入力
    int N; // 要素数
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // ヒープソート
    HeapSort(a);

    // 結果出力
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << a[i] << endl;
    }
}