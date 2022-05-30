#include<iostream>
#define MAX 27
using namespace std;

struct Node {
    char left;
    char right;
};

Node tree[MAX];
int N;

void preorder(char node) {
    if (node == '.')
        return;
    cout << node;
    preorder(tree[node - 'A'].left);
    preorder(tree[node - 'A'].right);
}

void inorder(char node) {
    if (node == '.')
        return;
    inorder(tree[node - 'A'].left);
    cout << node;
    inorder(tree[node - 'A'].right);
}

void postorder(char node) {
    if (node == '.')
        return;
    postorder(tree[node - 'A'].left);
    postorder(tree[node - 'A'].right);
    cout << node;
}

int main() {
    cin >> N;
    char node, left, right;
    for (int i = 0; i < N; i++) {
        cin >> node >> left >> right;
        tree[node - 'A'].left = left;
        tree[node - 'A'].right = right;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout << "\n";
}
