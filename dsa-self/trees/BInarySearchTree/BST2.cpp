#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    Node *insert(Node *root, int key)
    {
        if (!root)
            return new Node(key);
        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        return root;
    }

    void inorder(Node *root)
    {
        if (!root)
            return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
};

int main()
{
    BST bst;
    Node *root = nullptr;
    root = bst.insert(root, 50);
    root = bst.insert(root, 30);
    root = bst.insert(root, 20);
    root = bst.insert(root, 40);
    root = bst.insert(root, 70);
    root = bst.insert(root, 60);
    root = bst.insert(root, 80);

    cout << "Inorder traversal of the BST is: ";
    bst.inorder(root);
    return 0;
}