#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int v = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with Data: " << v;
    }
};

void insertNode(Node *&tail, int element, int data)
{
    // assuming that the element is present in the list

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empty list;
        // assuming that the element is non empty list;

        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found -> curr is representing element;
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *&tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    insertNode(tail, 3, 7);
    print(tail);

    return 0;
}