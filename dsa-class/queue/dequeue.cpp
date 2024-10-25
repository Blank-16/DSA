#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Node *implementDeque(int n)
{
    struct Node *newNode = new Node();
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int n)
{
    struct Node *newNode1 = new Node();
    newNode1->data = n;
    newNode1->next = *head;
    *head = newNode1;
}

void insertAtEnd(struct Node **head, int n)
{
    struct Node *newNode1 = new Node();
    newNode1->data = n;
    newNode1->next = NULL;
    if (*head == NULL)
    {
        *head = newNode1;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode1;
}

void deleteAtFront(struct Node **head)
{
    if (*head == NULL)
    {
        cout << "Deque is empty" << endl;
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    delete temp;
}

void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        cout << "Deque is empty" << endl;
        return;
    }
    if ((*head)->next == NULL)
    {
        delete *head;
        *head = NULL;
        return;
    }
    struct Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void printDeque(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    struct Node *head = NULL;
    head = implementDeque(1);
    insertAtBeginning(&head, 0);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    printDeque(head);
    deleteAtFront(&head);
    printDeque(head);
    deleteAtEnd(&head);
    printDeque(head);
    deleteAtEnd(&head);
    printDeque(head);
    deleteAtEnd(&head);
    printDeque(head);
    deleteAtEnd(&head);
    printDeque(head);
    return 0;
}
