//leetcode 700
//search in a binary search tree

#include <iostream>
using namespace std;
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
Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

// Search in BST (Recursive)
Node* searchBST(Node* root, int val) {
    if (root == nullptr)
        return nullptr;

    if (root->val == val)
        return root;
    else if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}
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
        root = insert(root, x);
    }

    cout << "\nInorder Traversal of BST: ";
    inorder(root);

    int key;
    cout << "\n\nEnter value to search: ";
    cin >> key;

    Node* result = searchBST(root, key);

    if (result != nullptr)
        cout << key << " is found in the BST." << endl;
    else
        cout << key << " is not found in the BST." << endl;

    return 0;
}