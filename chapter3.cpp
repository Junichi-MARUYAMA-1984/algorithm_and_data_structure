#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int result = 0;
    for (int i = 1; i < N; ++i) {
        if (i > K) {
            break;
        }
        for (int j = i; j < N - i; ++j) {
            int diff = N - i - j;
            if (diff <= K && diff >= i && diff >= j) {
                ++result;
            } else {
                continue;
            }
        }
    }

    cout << result << endl;
}