#include <iostream>
#include <vector>
using namespace std;

const int INF = 200000000;

int main() {
    // 入力受け取り
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int min_value = INF;
    int max_value = -INF;
    for (int i = 0; i < N; ++i) {
        if (a[i] < min_value) {
            min_value = a[i];
        }

        if (a[i] > max_value) {
            max_value = a[i];
        }
    }

    cout << max_value - min_value << endl;
}