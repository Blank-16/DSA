#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int value;
    Node *next;
};

void printList(Node *n)
{
    while(n != NULL)
    {
        cout << n->value << endl;
        n = n->next;
    }
};

void insertAtBeg(Node** head,int newValue)
{
    //Prepare a new node;

    Node* newNode = new Node();
    newNode->value = newValue;

    //Put in front of current head;

    newNode->next = *head;

    // Mode head of the list point to the new Node;
    
    *head = newNode;
      
};


void insertAtEnd(Node** head, int newValue)
{
    //Prepare a new node;
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = NULL;
    //if linked list is empty, newnode will be a head node;
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    //find the last node;
    Node* last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    
    //insert newNode after last node (at the end);
    
    last->next = newNode;

};

void insertAfterNode(Node* previous, int newValue)
{
    //Check if the given previous node is NULL;

    if(previous == NULL)
    {
        cout << "The given previous node cannot be NULL";
        return;
    }

    //Prepare a new node;

    Node* newNode = new Node();
    newNode->value = newValue;

    //insert newNode after Previous node;
    
    newNode->next = previous->next;
    previous->next = newNode;
};


int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head-> value = 1;
    head-> next = second;
    second-> value = 2;
    second-> next = third;
    third-> value = 3;
    third-> next = NULL;
    insertAtBeg(&head, 0);
    insertAtBeg(&head, -1);
    // array<int, 5> arr = {1, 2, 3, 4, 5};
    // for(int i = 0; i < arr.size(); i++)
    // {
    //     insertAtBeg(&head, arr[i]);
    // }
    insertAtEnd(&head, 4);
    printList(head);    
    return 0;
}




// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int value)
//     {
//         data = value;
//         next = NULL;
//     }
// };

// Node *createLinkedList(int arr[], int index, int size)
// {
//     if(index == size)
//         return NULL;

//     Node *temp;
//     temp = new Node(arr[index]);
//     temp->next = createLinkedList(arr, index + 1, size);
//     return temp;
// }

// int main()
// {
//     Node *head;
//     head = NULL;

//     int arr[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
//     for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//     {
//         if (head == NULL)
//         {
//             head = new Node(arr[i]);
//         }
//         else
//         {
//             Node *temp;
//             temp = new Node(arr[i]);
//             temp->next = head;
//             head = temp;
//         }
//     }
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     return 0;
// }


// int main()
// {
//     Node *head, *tail;
//     tail = head = NULL;

//     int arr[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
//     for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//     {
//         if (head == NULL)
//         {
//             head = new Node(arr[i]);
//             tail = head;
//         }
//         else
//         {
//             tail->next = new Node(arr[i]);
//             tail = tail->next;
//         }
//     }
//     Node *temp;
//     temp = head;

//     while (temp)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
// }

