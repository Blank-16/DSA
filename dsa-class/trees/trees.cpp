/* #include <bits/stdc++.h>
using namespace std;

struct  Node
{
    int  data;
    struct Node* left;
    struct Node* right; 
};

struct Node* createNode(int data)
{
    struct Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int main()
{
    struct  Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    cout << "in-order traversal before insertion: \n";

}

*/

#include <iostream>
using namespace std;

// Struct for a tree node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Class for the binary tree
class BinaryTree
{
public:
    TreeNode *root;

    BinaryTree() : root(nullptr) {}

    // Function to insert a new node
    void insert(int val)
    {
        root = insertRec(root, val);
    }

    // Inorder traversal
    void inorder()
    {
        inorderRec(root);
        cout << endl;
    }

    void preorder(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
private:
    // Recursive function to insert a new node
    TreeNode *insertRec(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }
        if (val < node->data)
        {
            node->left = insertRec(node->left, val);
        }
        else
        {
            node->right = insertRec(node->right, val);
        }
        return node;
    }

    // Recursive inorder traversal
    void inorderRec(TreeNode *node)
    {
        if (node != nullptr)
        {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }
};

int main()
{
    BinaryTree tree;
    
    for(int a=0; a<10; a++)
    {
        tree.insert(a);
    }
    cout << "Inorder traversal: ";
    tree.inorder(); 
    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;
    cout << "Postorder traversal: ";
    tree.postorder(tree.root);
    return 0;
}
