#include <iostream>
#include <vector>
using namespace std;

bool func(int i, int w, const vector<int>& a) {
    // ベースケース
    if (i == 0) {
        if (w == 0) {
            return true;
        } else {
            return false;
        }
    }

    // a[i - 1]を選ばない場合
    if (func(i - 1, w, a)) {
        return true;
    }

    // a[i - 1]を選ぶ場合
    if (func(i - 1, w - a[i - 1], a)) {
        return true;
    }

    // どちらもfalseの場合は、false
    return false;   
}

int main() {
    // 入力
    int N, W;
    cin >> N >> W;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // 再帰的に解く
    if (func(N, W, a)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}