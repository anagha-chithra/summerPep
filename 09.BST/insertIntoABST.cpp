/*
    leetcode 701
    insert into a binary search tree
*/

#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Insert into BST (Recursive)
Node* insertIntoBST(Node* root, int val) {
    Node* newNode = new Node(val);

    if (root == nullptr) {
        root = newNode;
        return root;
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the node values: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertIntoBST(root, x);
    }

    cout << "\nInorder Traversal before insertion: ";
    inorder(root);

    int val;
    cout << "\n\nEnter value to insert: ";
    cin >> val;

    root = insertIntoBST(root, val);

    cout << "\nInorder Traversal after insertion: ";
    inorder(root);

    cout << endl;

    return 0;
}