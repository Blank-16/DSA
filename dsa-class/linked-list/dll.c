#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createNode(int value)
{
    struct node *node1 = (struct node *)malloc(sizeof(struct node *));
    node1->data = value;
    node1->next = NULL;
    node1->prev = NULL;
    return node1;
}

struct node* forwardTraversal(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

struct node* insertAtBeg(struct node* head, int value)
{
    struct node* node1 = createNode(value);
    if(head == NULL)
    {
        return head;
    }
    node1->next = head;
    head->prev = node1;
    return node1;
}

struct node* deleteAtFirst(struct node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    struct node* temp = head;
    if(head!=NULL)
    {
        head->prev = NULL;
        free(temp);
        return head;
    }
}

struct  node* deleteAtLast(struct node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}


void backwardsTraversal(struct node *head)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->prev;
    }
}

struct node* insertAtLast(struct node* head, int value)
{
    struct node* node1 = createNode(value);
    if(head == NULL)
    {
        return node1;
    }
    struct node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node1;
    node1->prev = temp;
    return head;
}

struct node* insertAtPos(struct node* head, int pos)
{
    struct node* node1 = createNode(99);
    struct node* temp = head;

    for(int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    node1->next = temp->next;
    temp->next->prev = node1;
    temp->next = node1;
    node1->prev = temp;
    return head;
}

struct node* deleteAtPos(struct node* head, int pos)
{
    struct node* temp = head;
    for(int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    struct node* temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;
    free(temp1);
    return head;
}

int main()
{
    struct node *head = createNode(10);
    struct node *second = createNode(20);
    struct node *third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // printf("%d \n", head->data);
    // printf("%d \n", third->data);
    insertAtBeg(head, 99);
    printf("Forward traversal:\n");
    forwardTraversal(head); printf("\n");
    printf("Backwards traversal:\n");
    backwardsTraversal(head);

    return 0;
}
