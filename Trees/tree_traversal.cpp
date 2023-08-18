#include <iostream>

using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Inorder traversal
void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Pre-order traversal
void preorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order traversal
void postorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    // Construct a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Inorder traversal
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    // Pre-order traversal
    cout << "Pre-order traversal: ";
    preorder(root);
    cout << endl;

    // Post-order traversal
    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}

