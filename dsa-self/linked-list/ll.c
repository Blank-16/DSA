#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createNode(struct node *head, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *ptr = NULL;
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

struct Node *addBeg(struct Node *head, int data)
{
    struct node *ptr = (struct Node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = head;
    head = ptr;
    return head;
}

void addBeg(struct node **head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    temp->next = *head;
    *head = temp;
}

void addAtEnd(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
struct node *addAtEndOptimised(struct node *ptr, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    ptr->next = temp;
    return temp;
}
void countOfNodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("Linked list is empty.\n");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("%d\n", count);
}

void printData(struct node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
}