#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to check if the stack is empty
int isEmpty(struct Node *top)
{
    return top == NULL;
}

// Function to push an element onto the stack
void push(struct Node **top, int data)
{
    struct Node *temp = newNode(data);
    temp->next = *top;
    *top = temp;
    printf("%d pushed to stack\n", data);
}

// Function to pop the top element from the stack
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Cannot pop any elements as stack is empty. \n");
        return -1;
    }
    struct Node *temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to get the top element of the stack (peek)
int peek(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Function to print all the elements in the stack
void printStack(struct Node *top)
{
    struct Node *temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *stack = NULL; // Initially, stack is empty

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(stack); // Should print: 30 20 10

    printf("%d popped from stack\n", pop(&stack)); // Should print: 30 popped from stack
    printStack(stack);                             // Should print: 20 10

    printf("Top element is %d\n", peek(stack)); // Should print: Top element is 20

    return 0;
}
