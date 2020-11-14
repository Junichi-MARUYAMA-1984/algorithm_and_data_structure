#include <iostream>
using namespace std;

int main() {
    cout << "Start Game!" << endl;

    // Aさんの数の候補を表す区間を、[left, right)とする。。
    int left = 20, right = 36;

    // Aさんの数を1つに絞り切れないうちは繰り返す。
    while (right - left > 1) {
        int mid = left + (right - left) / 2; // 区間の真ん中

        // mid以上かどうかを訊いて、回答をyes/noで受け取る
        cout << "Is the age less than " << mid << " ? (yes / no)" << endl;
        string ans;
        cin >> ans;

        // 回答に応じて、あり得る数の範囲を絞る
        if (ans == "yes") {
            right = mid;
        } else {
            left = mid;
        }
    }

    // ズバリ当てる！
    cout << "The age is " << left << "!" << endl;
}