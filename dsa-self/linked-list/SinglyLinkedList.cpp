#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  ~Node()
  {
    int value = this->data;
    if (this->next != NULL)
    {
      delete next;
      next = NULL;
    }
    cout << "Memory is free for node with data: " << value << endl;
  }
};

void insertAtHead(Node *&head, int data)
{
  // new node create
  Node *temp = new Node(data);
  temp->next = head;
  head = temp;
}

void insertAtTail(Node *&tail, int data)
{
  Node *temp = new Node(data);
  tail->next = temp;
  tail = temp;
}

void insertAtPos(Node *&head, Node *&tail, int pos, int data)
{
  if (pos == 1)
  {
    insertAtHead(head, data);
    return;
  }

  Node *temp = head;
  int count = 1;
  while (count < pos - 1)
  {
    temp = temp->next;
    count++;
  }

  // inserting at last pos;
  if (temp->next == NULL)
  {
    insertAtTail(tail, data);
    return;
  }

  // creating a node for d;
  Node *nodeToInsert = new Node(data);
  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
}

void deleteNode(Node *&head, Node *&tail, int pos)
{
  if (pos == 1)
  {
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return;
  }
  else
  {
    // deleting any middle or last node;
    Node *curr = head;
    Node *prev = NULL;
    int count = 1;
    while (count < pos)
    {
      prev = curr;
      curr = curr->next;
      count++;
    }

    prev->next = curr->next;
    if (curr->next == NULL)
    {
      tail = prev;
    }
    curr->next = NULL;
    delete curr;
  }
}

void printList(Node *&head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  Node *node1 = new Node(10);
  Node *head = node1;
  Node *tail = node1;
  insertAtTail(tail, 15);
  insertAtTail(tail, 11);
  insertAtPos(head, tail, 2, 89);
  printList(head);
  cout << "tail: " << tail->data << endl
       << "head: " << head->data << endl;
  deleteNode(head, tail, 4);
  printList(head);
  cout << "tail: " << tail->data << endl
       << "head: " << head->data << endl;
}
