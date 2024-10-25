#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct Que{
    Node* front;
    Node* rear;
}Que;

Node* createNode(int value)
{
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->data = value;
    node1->next = NULL;
    return node1;
}
Que* createQue()   // initializing only 
{
    Que* que= (Que*)malloc(sizeof(Que));
    que->front = NULL;
    que->rear = NULL;
    return que;
}

int isEmpty(Que* que)
{
    return que->front > que->rear;
}

void Enque(Que* que, int data)
{
    Node* newNode = createNode(data);
    if(que->rear == NULL)
    {
        que->front = que->rear = newNode; // can be wrong here
        return;
    }
    que->rear->next = newNode;
    que->rear = newNode;
}

int deque(Que* que)
{
    if(que->front == NULL){
        printf("Que is empty. cammpt dequeue");
        return -1;
    }
    Node* temp = que->front;
    que->front = que->front->next;

    if(que->front == NULL)
        que->rear = NULL;

    int dequeData = temp->data;
    free(temp);
    return dequeData;
}

void displayQue(Que* que){
    Node* temp = que->front;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{   
    Que* que = createQue();
    Enque(que, 10);
    Enque(que, 20);
    Enque(que, 30);
    Enque(que, 40);
    Enque(que, 50);
    displayQue(que);
}
