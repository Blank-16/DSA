#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class linkedList
{
    Node *head;

public:
    linkedList() : head(NULL) {};

    void insertAtBeg(int data)
    {
        Node *temp = new Node(data);
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    void insertAtend(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPosition(int value, int pos)
    {
        if (pos < 1)
        {
            cout << "Position should be >= 1.\n";
            return;
        }
        if (pos == 1)
        {
            insertAtBeg(value);
        }
        Node *newNode = new Node();
        newNode->data = value;

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp; ++i)
        {
            temp = temp->next;
        }

        if (!temp)
        {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAtHead(int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        temp->next = this->head;
        this->head = temp;
    }

    void printLinkedList()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "List empty\n";
            return;
        }
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    linkedList list;

    // Inserting nodes

    list.insertAtBeg(5);
    list.insertAtBeg(4);
    list.insertAtBeg(3);
    list.insertAtBeg(2);
    list.insertAtBeg(1);

    cout << "Elements of the list are: ";

    list.printLinkedList();
    cout << endl;

    return 0;
}