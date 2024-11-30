#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int key, height;
    Node *left;
    Node *right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree
{
public:
    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right; // temp =a, a=b, b=temp
        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    Node *insert(Node *node, int key)
    {
        if (!node)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rotateRight(node);
        if (balance < -1 && key > node->right->key)
            return rotateLeft(node);
        if (balance > 1 && key > node->left->key)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && key < node->right->key)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
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
    AVLTree avl;
    Node *root = nullptr;
    root = avl.insert(root, 10);
    root = avl.insert(root, 20);
    root = avl.insert(root, 30);
    root = avl.insert(root, 40);
    root = avl.insert(root, 50);
    root = avl.insert(root, 25);

    cout << "Inorder traversal of the AVL tree is: ";
    avl.inorder(root);
    return 0;
}