#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
// vector<int> heap[MAX];
int heap[MAX];
int heapSize = 0;

void insert(int value)
{
    if (heapSize >= MAX)
    {
        cout << "Heap is full\n";
        return;
    }

    heap[heapSize] = value;
    int current = heapSize;
    heapSize++;
    while (current > 0 && heap[(current - 1) / 2] < heap[current])
    {
        int temp = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = heap[current];
        heap[current] = temp;

        current = (current - 1) / 2;
    }
}

void displayHeap()
{
    for (int i = 0; i < heapSize; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int deleteMax()
{
    if (heapSize <= 0)
    {
        cout << "Heap is empty\n";
        return -1;
    }
    int max = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    int current = 0;
    while (current * 2 + 1 < heapSize)
    {
        int left = current * 2 + 1;
        int right = current * 2 + 1;
        int maxChild = left;

        if (right < heapSize && heap[right] > heap[left])
        {
            maxChild = right;
        }
        if (heap[current])
        {
        }
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(5);
    insert(15);
    insert(30);

    cout << "heap elements: ";
    displayHeap();
    cout << "Deleted max element: ";
}