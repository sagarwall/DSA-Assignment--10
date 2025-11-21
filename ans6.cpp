#include <iostream>
#include <unordered_set>
using namespace std;

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to check duplicates using preorder traversal
bool hasDuplicates(Node* root, unordered_set<int>& values) {
    if (root == nullptr)
        return false;

    if (values.find(root->data) != values.end())
        return true; // duplicate found

    values.insert(root->data);

    return hasDuplicates(root->left, values) || hasDuplicates(root->right, values);
}

// Wrapper function
bool containsDuplicate(Node* root) {
    unordered_set<int> values;
    return hasDuplicates(root, values);
}

int main() {
    // Create binary tree
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(2); // duplicate

    if (containsDuplicate(root))
        cout << "Duplicates Found\n";
    else
        cout << "No Duplicates\n";

    return 0;
}
