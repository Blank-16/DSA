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
    linkedList()
    {
        this->head = nullptr;
    };

    void insertAtBeg(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void insertAtend(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteAtBeg()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtend()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    Node *insertatPos(Node *head, int pos, int data)
    {
        if (pos < 1)
        {
            return head;
        }
        if (pos == 1)
        {
            Node *newNode = new Node(data);
            newNode->next = head;
            return newNode;
        }
        Node *curr = head;
        for (int i = 1; i < pos - 1 && curr != nullptr; i++)
        {
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            return head;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;

        return head;
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

    int n;
    cout << "Enter total list elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter element no. " << i + 1 << " : ";
        cin >> data;
        list.insertAtBeg(data);
    }
    cout << "Elements of the list are: ";

    list.printLinkedList();
    cout << endl;

    return 0;
}