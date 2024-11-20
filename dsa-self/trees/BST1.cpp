#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node *root;

    Node *insertRec(Node *node, int value)
    {
        if (node == NULL)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertRec(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void inorderRec(Node *node)
    {
        if (node == NULL)
            return;

        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    Node *searchRec(Node *node, int value)
    {
        if (node == NULL || node->data == value)
        {
            return node;
        }

        if (value < node->data)
        {
            return searchRec(node->left, value);
        }

        return searchRec(node->right, value);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insertRec(root, value);
    }

    void inorder()
    {
        inorderRec(root);
        cout << endl;
    }

    bool search(int value)
    {
        Node *result = searchRec(root, value);
        return result != NULL;
    }
};

int main()
{
    BST tree;

    // Insert some values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Print inorder traversal
    cout << "Inorder traversal: ";
    tree.inorder();

    // Search for values
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;

    return 0;
}