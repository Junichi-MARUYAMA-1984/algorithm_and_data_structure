#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 連結リストの各ノードを表す構造体
struct Node {
    Node* next; // 次がどのノードを指すか
    string name; // ノードに付随している値

    Node(string name_ = "") : next(NULL), name(name_) {}
};

// 番兵(sentinel)を表すノードをグローバル領域においておく
Node* nil;

// 初期化
void init() {
    nil = new Node();
    nil->next = nil; // 初期状態ではnilがnilを指すようにする
}

// 連結リストを出力する
void printList() {
    Node* cur = nil->next; // 先頭から出発
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// ノードpの直後にノードvを挿入する。
// ノードpのデフォルト引数をnilとしておく。
// そのため、insert(v)を呼び出す操作はリストの先頭への挿入を表す。
void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    p->next = v;
}

int main() {
    // 初期化
    init();

    // 作りたいノードの名前の一覧
    // 最後尾のノード「山本」から順に挿入することに注意する。
    vector<string> names = {"yamamoto", 
                            "watanabe",
                            "ito",
                            "takahashi",
                            "suzuki",
                            "saito"};
    
    // 各ノードを生成して、連結リストの先頭に挿入していく。
    for (int i = 0; i < (int)names.size(); ++i) {
        // ノードを作成する
        Node* node = new Node(names[i]);

        // 作成したノードを連結リストの先頭に挿入する。
        insert(node);

        // 各ステップの連結リストの様子を出力する。
        cout << "step " << i << ": ";
        printList();
    }
}