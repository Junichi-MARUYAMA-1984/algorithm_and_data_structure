#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000; // ここでは配列の値は100000未満とする

// バケットソート
void BucketSort(vector<int> &a) {
    int N = (int)a.size();

    // 各要素の個数をカウントする
    // num[v]: vの個数
    vector<int> num(MAX, 0);
    for (int i = 0; i < N; ++i) {
        ++num[a[i]]; // a[i]の出現回数をカウントする
    }

    // numの累積和を取る。
    // sum[v]: v以下の値の個数
    // 値a[i]が全体の中で何番目に小さいかを求める。
    vector<int> sum(MAX, 0);
    for (int v = 1; v < MAX; ++v) {
        sum[v] = sum[v - 1] + num[v];
    }

    // sumをもとにソート処理。
    // a2: aをソートしたもの
    vector<int> a2(N);
    for (int i = N - 1; i >= 0 ; --i) {
        a2[--sum[a[i]]] = a[i];
    }
    a = a2;
}

int main() {
    // 入力
    int N; // 要素数
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // バケットソート
    BucketSort(a);

    // 結果出力
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << a[i] << endl;
    }
}