#include <iostream>
#include <vector>
using namespace std;

int how_many_times(int N) {
    int exp = 0; // 2で割り切れた回数
    while (N % 2 == 0) {
        N /= 2;
        ++exp;
    }
    return exp;
}

// 無限大を表す値
const int INF = 1234567890;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // A[N]各要素における「2で割り切れる回数」をそれぞれ求め、その中の最小値を求める。
    int result = INF;
    for (auto a : A) {
        result = min(result, how_many_times(a));
    }

    cout << result << endl;
}