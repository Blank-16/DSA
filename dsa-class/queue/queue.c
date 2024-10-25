#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Que
{
    int  front;
    int rear;
    int arr[MAX];
};

void initQue(struct Que* que)
{
    que->front=0;
    que->rear=-1;
}

int isFull(struct Que* que)
{
    return que->rear = MAX-1;
}
int isEmpty(struct Que* que)
{
    return que->front > que->rear;                      
}

void Enque(struct Que* que, int value)
{
    if(isFull(que))
    {
        printf("Cannot insert any element as que is full, overflow\n");
        return;
    }
    printf("Value inserted is %d\n", value);
    que->arr[++que->rear]=value;
}
int deque(struct Que* que)
{
    if(isEmpty(que))
    {
        printf("Queue is empty, cannot dequeue");
        return -1;
    }
    int value = que->arr[que->front];
    if(que->front == que->rear)
    {
        que->front = que->rear = -1;
    }
    else{
        que->front++;
    }
    que->front++;
    return value;
}
int main()
{
    struct Que que;
    initQue(&que);
    Enque(&que, 10);
    Enque(&que, 20);
    Enque(&que, 30);
    Enque(&que, 40);
    Enque(&que, 50);
    return 0;
}
