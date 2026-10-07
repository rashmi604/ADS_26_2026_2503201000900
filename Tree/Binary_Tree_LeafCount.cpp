#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to create a binary tree
Node* create(int x)
{
    Node *newNode = new Node();

    cout << "Enter (-1) for no data: ";
    cin >> x;

    if (x == -1)
        return NULL;

    newNode->data = x;

    cout << "Enter left child of " << x << ": ";
    newNode->left = create(x);

    cout << "Enter right child of " << x << ": ";
    newNode->right = create(x);

    return newNode;
}

// Count leaf nodes
int leafcount(Node *p)
{
    if (p == NULL)
        return 0;

    if (p->left == NULL && p->right == NULL)
        return 1;

    return leafcount(p->left) + leafcount(p->right);
}

// Count internal nodes
int internalcount(Node *p)
{
    if (p == NULL)
        return 0;

    if (p->left != NULL || p->right != NULL)
        return 1;

    return internalcount(p->left) + internalcount(p->right);
}

// Count total nodes
int totalnodes(Node *p)
{
    if (p == NULL)
        return 0;

    return totalnodes(p->left) + totalnodes(p->right);
}

// Preorder Traversal
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder Traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder Traversal
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root;

    // Create the tree
    root = create(0);

    // Count leaf nodes
    cout << "\nNumber of leaf nodes = "
         << leafcount(root) << endl;

    // Count internal nodes
    cout << "\nNumber of internal nodes = " << internalcount(root) << endl;   

    // Count Total nodes 
    cout << "Total nodes = " << totalnodes(root);
    // Traversals
    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}