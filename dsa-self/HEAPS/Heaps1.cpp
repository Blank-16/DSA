#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    vector<int> heap;

    void heapifyDown(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i)
    {
        int parent = (i - 1) / 2;
        if (i && heap[i] > heap[parent])
        {
            swap(heap[i], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    void insert(int key)
    {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void deleteRoot()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void printHeap()
    {
        for (int num : heap)
            cout << num << " ";
        cout << endl;
    }
};

int main()
{
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(40);
    h.insert(50);
    h.insert(100);
    h.insert(25);

    cout << "Heap elements: ";
    h.printHeap();

    h.deleteRoot();
    cout << "Heap after deleting root: ";
    h.printHeap();

    return 0;
}