#include <iostream>
#include <vector>

using namespace std;

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void display(int arr[], int size);
void swap(int &a, int &b);

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, size - 1);
    display(arr, size);
    vector<int> arr2 = {12,234,123,35,1235,135,463,1231,1};
    quicksort(&arr2[0], 0, arr2.size() - 1);
    display(&arr2[0], arr2.size());
    return 0;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
