#include <iostream>
#include <vector>

using namespace std;

// Priority Queue class using Max Heap
class PriorityQueue
{
    vector<int> heap; // Vector to store the heap

    // Helper function to maintain heap property while inserting an element
    void heapifyUp(int index)
    {
        if (index == 0)
            return; // Base case: root node

        int parentIndex = (index - 1) / 2;

        // If current node is greater than its parent, swap them
        if (heap[index] > heap[parentIndex])
        {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex); // Recursive call to maintain heap property up the tree
        }
    }

    // Helper function to maintain heap property while removing the maximum element
    void heapifyDown(int index)
    {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // Compare with the left child
        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;

        // Compare with the right child
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;

        // If the largest is not the current index, swap and heapify down further
        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest); // Recursive call to maintain heap property down the tree
        }
    }

public:
    // Function to insert a new element into the priority queue
    void push(int value)
    {
        heap.push_back(value);      // Add the new value at the end of the vector
        heapifyUp(heap.size() - 1); // Adjust the heap property upwards
    }

    // Function to remove and return the maximum element (highest priority)
    int pop()
    {
        if (heap.size() == 0)
        {
            cout << "Priority queue is empty!" << endl;
            return -1;
        }

        int maxValue = heap[0]; // The root of the heap is the maximum element
        heap[0] = heap.back();  // Move the last element to the root
        heap.pop_back();        // Remove the last element
        heapifyDown(0);         // Adjust the heap property downwards

        return maxValue;
    }

    // Function to return the maximum element without removing it
    int top()
    {
        if (heap.size() == 0)
        {
            cout << "Priority queue is empty!" << endl;
            return -1;
        }
        return heap[0]; // The root element is the maximum
    }

    // Function to check if the priority queue is empty
    bool empty()
    {
        return heap.size() == 0;
    }

    // Function to return the size of the priority queue
    int size()
    {
        return heap.size();
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
