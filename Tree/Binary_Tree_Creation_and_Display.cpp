#include <iostream>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Function to create the binary tree recursively
Node* create() {
    int x;
    Node *newNode = new Node();
    
    cout << "Enter data (-1 for no data): ";
    cin >> x;
    
    if (x == -1) {
        return NULL;
    }
    
    newNode->data = x;
    
    cout << "Enter left child for " << x << "\n";
    newNode->left = create();
    
    cout << "Enter right child for " << x << "\n";
    newNode->right = create();
    
    return newNode;
}

// Preorder traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal (Left -> Root -> Right)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Main function
int main() {
    Node *root = NULL;
    
    cout << "--- Binary Tree Creation ---\n";
    root = create();
    
    cout << "\nPreorder Traversal: ";
    preorder(root);
    
    cout << "\nInorder Traversal: ";
    inorder(root);
    
    cout << "\nPostorder Traversal: ";
    postorder(root);
    
    cout << endl;
    return 0;
}