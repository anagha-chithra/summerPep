/*
    leetcode 230
    kth Smallest Element in a binary search tree
*/
#include <iostream>
#include <vector>
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
void displayInorder(Node* root) {
    if (!root)
        return;

    displayInorder(root->left);
    cout << root->val << " ";
    displayInorder(root->right);
}


void inorder(Node* root, vector<int>& arr) {
    if (!root)
        return;

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}
// Find kth smallest element
int kthSmallest(Node* root, int k) {
    vector<int> arr;
    inorder(root, arr);

    if (k < 1 || k > arr.size())
        return -1;

    return arr[k - 1];
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
    displayInorder(root);

    int k;
    cout << "\nEnter the value of k: ";
    cin >> k;

    int ans = kthSmallest(root, k);

    if (ans == -1)
        cout << "Invalid value of k." << endl;
    else
        cout << "The " << k << "th smallest element is: " << ans << endl;

    return 0;
}