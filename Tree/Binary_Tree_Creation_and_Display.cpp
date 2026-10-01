#include <iostream>
using namespace std;

// Structure for a binary tree node[span_1](start_span)[span_1](end_span)
struct Node {
    int data;
    Node *left;
    Node *right;
};

// Function to create the binary tree recursively[span_2](start_span)[span_2](end_span)
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

// Preorder traversal (Root -> Left -> Right)[span_3](start_span)[span_3](end_span)
void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal (Left -> Root -> Right)[span_4](start_span)[span_4](end_span)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder traversal (Left -> Right -> Root)[span_5](start_span)[span_5](end_span)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Main function[span_6](start_span)[span_6](end_span)
int main() {
    Node *root = NULL;
    
    cout << "--- Binary Tree Creation ---\n";
    root = create();[span_7](start_span)[span_7](end_span)
    
    cout << "\nPreorder Traversal: ";
    preorder(root);[span_8](start_span)[span_8](end_span)
    
    cout << "\nInorder Traversal: ";
    inorder(root);[span_9](start_span)[span_9](end_span)
    
    cout << "\nPostorder Traversal: ";
    postorder(root);[span_10](start_span)[span_10](end_span)
    
    cout << endl;
    return 0;
}