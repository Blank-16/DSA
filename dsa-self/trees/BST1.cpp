#include <bits/stdc++.h>
using namespace std;
struct NODE
{
    int data;
    NODE *left;
    NODE *right;
    NODE(int value)
    {
        data = value;
        left = right = NULL;
    }
};

NODE *search(NODE *head, int value)
{
    if (head == NULL || head->data == value)
    {
        return head;
    }
    if (head->data < value)
    {
        return search(head->right, value);
    }
    return search(head->left, value);
}

NODE *insert(NODE *node, int key)
{
    if (node == NULL)
        return new NODE(key);

    if (node->data == key)
        return node;

    if(node->data < key)
        node->right = insert(node->right, key);
    
    else 
        node->left = insert(node->left, key);

    return node;
}

void inorder(NODE *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    
}

int main()
{
}