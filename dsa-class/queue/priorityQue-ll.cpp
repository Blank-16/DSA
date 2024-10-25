#include <iostream>
using namespace std;

// Node structure for linked list
struct Node
{
    int data;
    Node *next;
};

// Priority Queue class using Linked List
class PriorityQueue
{
private:
    Node *front; // Points to the front of the queue (highest priority element)

public:
    // Constructor to initialize the queue
    PriorityQueue()
    {
        front = nullptr;
    }

    // Function to insert an element in the queue based on priority
    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        // If the queue is empty or the new value has higher priority than the front
        if (front == nullptr || value > front->data)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            // Traverse the list to find the correct position for the new value
            Node *temp = front;
            while (temp->next != nullptr && temp->next->data >= value)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to remove and return the highest priority element (front of the list)
    int pop()
    {
        if (front == nullptr)
        {
            cout << "Priority queue is empty!" << endl;
            return -1;
        }

        int highestPriorityValue = front->data; // The front element has the highest priority
        Node *temp = front;
        front = front->next; // Move the front pointer to the next node
        delete temp;         // Free the memory of the removed node

        return highestPriorityValue;
    }

    // Function to return the highest priority element without removing it
    int top()
    {
        if (front == nullptr)
        {
            cout << "Priority queue is empty!" << endl;
            return -1;
        }
        return front->data; // The front element has the highest priority
    }

    // Function to check if the queue is empty
    bool empty()
    {
        return front == nullptr;
    }

    // Function to return the size of the priority queue
    int size()
    {
        int count = 0;
        Node *temp = front;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Destructor to clean up memory
    ~PriorityQueue()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Main function to demonstrate the Priority Queue
int main()
{
    PriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    cout << "Top element (max): " << pq.top() << endl; // Should print 30

    cout << "Removing elements in priority order:" << endl;
    while (!pq.empty())
    {
        cout << pq.pop() << " "; // Should print 30 20 10 5
    }

    cout << endl;

    return 0;
}
