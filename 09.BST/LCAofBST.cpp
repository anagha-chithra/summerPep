/*
    leetcode 235
    lowest common ancestor of a BST
*/

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
    else
        root->right = insert(root->right, val);

    return root;
}
Node* search(Node* root, int val) {
    if (root == nullptr || root->val == val)
        return root;

    if (val < root->val)
        return search(root->left, val);

    return search(root->right, val);
}
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Lowest Common Ancestor
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == nullptr)
        return nullptr;

    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}

int main() {
    Node* root = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    int pVal, qVal;
    cout << "\n\nEnter first node value: ";
    cin >> pVal;

    cout << "Enter second node value: ";
    cin >> qVal;

    Node* p = search(root, pVal);
    Node* q = search(root, qVal);

    if (p == nullptr || q == nullptr) {
        cout << "One or both nodes are not present in the BST." << endl;
    } else {
        Node* lca = lowestCommonAncestor(root, p, q);
        cout << "Lowest Common Ancestor is: " << lca->val << endl;
    }

    return 0;
}