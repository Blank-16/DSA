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
            // left to complete
            if (heap[current] < heap[maxChild])
            {
                swap(heap[current], heap[maxChild]);
                current = maxChild;
            }
            else
            {
                break;
            }
        }
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = right;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i = n-1; i >= 0; i--)
    {
        //moving current root  to the end;
        swap(arr[0], arr[i]);
        //calling max heapify on the redyced heap;
        heapify(arr, i , 0);
    }
}

void printAraay(int arr[], int n){
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int deleteMin()
{
    if (heapSize <= 0)
    {
        cout << "Heap is empty";
        cout << endl;
    }
    int min = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;

    int current = 0;
    while (current * 2 + 1 < heapSize)
    {
        int left = current * 2 + 1;
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