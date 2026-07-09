/*
    leetcode 98
    validate Binary Search Tree
*/

#include <iostream>
#include <climits>
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
    else
        root->right = insert(root->right, val);

    return root;
}
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Helper function to validate BST
bool helper(Node* root, long minval, long maxval) {
    if (!root)
        return true;

    if (root->val <= minval || root->val >= maxval)
        return false;

    return helper(root->left, minval, root->val) &&
           helper(root->right, root->val, maxval);
}

// Validate BST
bool isValidBST(Node* root) {
    return helper(root, LONG_MIN, LONG_MAX);
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

    cout << "\nInorder Traversal: ";
    inorder(root);

    if (isValidBST(root))
        cout << "\n\nThe tree is a Valid BST." << endl;
    else
        cout << "\n\nThe tree is NOT a Valid BST." << endl;

    return 0;
}