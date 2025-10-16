#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // left part and right part 
    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] < pivot)
        {
            i++;
        }
        while(arr[j]> pivot)
        {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;

}

void quickSort(int arr[], int start, int end)
{
    // base case

    if (start >= end)
        return;

    // partition
    int p = partition(arr, start, end);

    // left part sorting
    quickSort(arr, start, p - 1);

    // right part sorting
    quickSort(arr, p + 1, end);
}

int main()
{
    int arr[] = {2, 4, 1, 6, 9, 3};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
