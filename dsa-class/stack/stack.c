#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node{
    int data;
    struct Node* next;
};

struct Stack {
    int top;
    int arr[MAX];
};

void initStack(struct Stack* stack)
{
    stack->top = -1;
}
int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}

int isFull(struct Stack* stack)
{
    return stack->top == MAX-1;
}

void push(struct Stack* stack, int value)
{
    if(isFull(stack))
    {
        printf("Stack overflow, cannot push a new element.\n");
        return;
    }
    printf("value inserted in the stack %d\n", value);
    stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack underflow, cannot pop an element.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(struct Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Cannot display top element, stack is empty. \n");
        return -1;
    }
    return stack->arr[stack->top];
}

int deleteMiddle(struct Stack* stack, int num)
{
    printf("Give the input elements of the stack: ");
    int arr[num];
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
        push(stack, arr[i]);
    }
    int mid = num/2;
    if(num % 2 == 0){
        mid++;
    }
    else if(num == 0){
        printf("No elements found in stack");
    }else{
        mid = mid;
    }
}

int removeMiddle(struct Stack* stack, int n, int curr)
{
    if(curr == n/2 )
    {
        pop(stack);
        return;
    }
    int temp = pop(stack);
    removeMiddle(stack, n, curr+1);
    push(stack, temp);

}


int main()
{
    // int num;
    // printf("Enter the number of elements you want to insert in the stack: ");
    // scanf("%d", &num);
    // struct Stack stack;
    // initStack(&stack);
    struct Stack stack;
    int n, i, value;
    initStack(&stack);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(&stack, value);
    }
    removeMiddle(&stack, n, 0);
    while (!isEmpty(&stack))
    {
        printf("%d ", pop(&stack));
    }
    printf("\n");
    return 0;
}
















