// #include <stdio.h>
// struct node {
//     int data;
//     struct node* next;

// };

// struct node* createNode(int value){
//     struct node* node1 = (struct node*) malloc(size(struct node));
//     node1 -> data = value;
//     node1 -> next = null;
//     return node1;

// };
// struct node* insertAtBeg(struct node* header, int value){
//     struct node* node1 = header -> next;
//     node1 -> next = header -> next;
//     header -> next = value;
//     header -> data+1;
//     return header;

// };

// void displayList(struct node* header){
//     struct node*current = header -> next;
//     if(current == NULL){
//         printf("The list is empty. \n");
//     }

// }

// struct node * deleteAtBeg(struct node* header){
//     if(header-> next == NULL){
//         printf("the list empty no node to delete.");
//         return header;
//     }
//     struct node * temp = header-> next;
//     header -> next = temp-> next;
//     free(temp);
//     header -> data-=1;

// }

// struct node* deleteAtEnd(struct ndoe* header){
//     if(header-> next ==NULL){
//         printf("The list is empty. No node to delete. \n");
//         return header;
//     }
//     struct ndoe* temp = header;
//     struct ndoe* prev = NULL;
//     while(temp-> next != NULL){
//         prev = temp;
//         temnp = temp -> next;
//     }
//     if(prev == header){
//         header-> next = NULL;
//     }else{
//         prev -> next = NULL;
//     }

// }

// struct node* deleteAtPos(struct node* header, int pos){
//     if(header -> next == NULL){
//         printf("List is empty\n");
//         return header;
//     }

//     struct node* temp = header;
//     struct node* prev = NULL;
//     for(int i  = 0; i < position; i++){
//         prev = temp;
//     }
// }

// struct node* insertatPos(struct node* header, int position , int data){
//     struct node* node1 = createNode(data);
//     struct node* temp = header;
//     for( int i =1; i< position;i++){
//         if(temp -> nextr == NULL){
//             printf("position %d is out of bounds");
//             break;
//         }
//         temp = temp-> next;
//     }
// }

// struct node* insertAtLast(struct node* header, int value){
//     struct node* temp = header;
//     while(temp -> next != NULL){
//         temp = temp -> next;
//         struct node* node1 = createNode(data);
//         temp -> next = node1;
//         header -> data += 1;
//         return header;

//     }
// }
// int main(){
//     struct ndoe* header = (struct node*) malloc(sizeof(struct node));
//     header-> data = 0;
//     header -> next = NULL;
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc()

struct node
{
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int value)
{
    struct node *node1 = (struct node *)malloc(sizeof(struct node));
    node1->data = value;
    node1->next = NULL;
    return node1;
}

// Function to insert a node at the beginning
struct node *insertAtBeg(struct node *header, int value)
{
    struct node *node1 = createNode(value);
    node1->next = header->next;
    header->next = node1;
    header->data += 1;  // Increment the count of nodes
    return header;
}

// Function to display the linked list
void displayList(struct node *header)
{
    struct node *current = header->next;
    if (current == NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Function to delete a node at the beginning
struct node *deleteAtBeg(struct node *header)
{
    if (header->next == NULL)
    {
        printf("The list is empty. No node to delete.\n");
        return header;
    }
    struct node *temp = header->next;
    header->next = temp->next;
    free(temp);
    header->data -= 1; // Decrement the count of nodes
    return header;
}

// Function to delete a node at the end
struct node *deleteAtEnd(struct node *header)
{
    if (header->next == NULL)
    {
        printf("The list is empty. No node to delete.\n");
        return header;
    }
    struct node *temp = header->next;
    struct node *prev = header;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == header)
    {
        header->next = NULL;
    }
    else
    {
        prev->next = NULL;
    }
    free(temp);
    header->data -= 1; // Decrement the count of nodes
    return header;
}

// Function to delete a node at a specific position
struct node *deleteAtPos(struct node *header, int pos)
{
    if (header->next == NULL)
    {
        printf("The list is empty.\n");
        return header;
    }
    struct node *temp = header->next;
    struct node *prev = header;
    for (int i = 0; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Position %d is out of bounds.\n", pos);
            return header;
        }
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    header->data -= 1; // Decrement the count of nodes
    return header;
}

// Function to insert a node at a specific position
struct node *insertAtPos(struct node *header, int position, int data)
{
    struct node *node1 = createNode(data);
    struct node *temp = header;
    for (int i = 1; i < position; i++)
    {
        if (temp->next == NULL)
        {
            printf("Position %d is out of bounds.\n", position);
            free(node1);
            return header;
        }
        temp = temp->next;
    }
    node1->next = temp->next;
    temp->next = node1;
    header->data += 1; // Increment the count of nodes
    return header;
}

// Function to insert a node at the end
struct node *insertAtLast(struct node *header, int value)
{
    struct node *temp = header;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node *node1 = createNode(value);
    temp->next = node1;
    header->data += 1; // Increment the count of nodes
    return header;
}
 
int main()
{
    struct node *header = (struct node *)malloc(sizeof(struct node));
    header->data = 0;
    header->next = NULL;

    // Example operations
    header = insertAtBeg(header, 10);
    header = insertAtLast(header, 20);
    header = insertAtPos(header, 2, 15);
    displayList(header);

    header = deleteAtBeg(header);
    header = deleteAtEnd(header);
    displayList(header);

    return 0;
}

// Structure Definition (struct node):

// A node structure is defined to represent each node in the linked list. It contains:
// int data: Stores the data value.
// struct node* next: A pointer to the next node in the list.
// Function createNode:

// This function creates a new node, initializes it with a value, and sets the next pointer to NULL.
// Function insertAtBeg:

// This function inserts a new node at the beginning of the list.
// The header node's next pointer is updated to point to the new node, and the data field in the header (used as a counter) is incremented.
// Function displayList:

// This function traverses the list starting from the first node (after the header) and prints the data values. If the list is empty, it prints a message.
// Function deleteAtBeg:

// This function deletes the first node after the header.
// If the list is empty, it prints a message and returns the unchanged header.
// Function deleteAtEnd:

// This function deletes the last node in the list.
// If the list is empty, it prints a message and returns the unchanged header.
// Function deleteAtPos:

// This function deletes a node at a specified position.
// It traverses the list to find the node at the given position and removes it.
// Function insertAtPos:

// This function inserts a new node at a specified position.
// It traverses the list to the given position and inserts the new node there.
// Function insertAtLast:

// This function inserts a new node at the end of the list.
// It traverses the list to the last node and updates its next pointer to the new node.
// main Function:

// The main function creates a header node and initializes it.
// It demonstrates the usage of the linked list functions by performing a few insertions, deletions, and displaying the list.
// Corrections Made:
// Syntax Errors: Corrected typographical errors such as size to sizeof, null to NULL, nextr to next, etc.
// Logic Errors: Corrected logic errors in insertAtBeg, deleteAtEnd, and other functions to ensure correct linked list operations.
// Memory Management: Proper handling of memory allocation (malloc) and deallocation (free).