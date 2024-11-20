#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    Node *root;

    // Helper function for recursive deletion
    void destroyTree(Node *node)
    {
        if (node)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    // Helper function for recursive inorder traversal
    void inorderTraversal(Node *node)
    {
        if (node)
        {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree()
    {
        destroyTree(root);
    }

    // Insert a new value into the binary tree
    void insert(int value)
    {
        if (!root)
        {
            root = new Node(value);
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        while (current)
        {
            parent = current;
            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (value < parent->data)
            parent->left = new Node(value);
        else
            parent->right = new Node(value);
    }

    // Print the tree in-order
    void printInorder()
    {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

// Main function for testing
int main()
{
    BinaryTree tree;

    // Insert some test values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    return 0;
}