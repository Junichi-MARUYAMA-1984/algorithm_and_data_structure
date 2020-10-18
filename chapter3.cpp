#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力受け取り
    int N, W;
    cin >> N >> W;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // bitは2^N通りの部分集合全体を動く。
    bool exist = false; // Wに一致する部分和があるか否かのフラグ。
    for (int bit = 0; bit < (1 << N); ++bit) {
        int sum = 0; // 部分集合に含まれる要素の和
        for (int i = 0; i < N; ++i) {
            // i番目の要素a[i]が、bitで指定されている部分集合に含まれているかどうか。
            // 含まれていたら和の計算に入れる。
            if (bit & (1 << i)) {
                sum += a[i];
            }
        }

        if (sum == W) {
            exist = true;
        }
    }

    if (exist) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}