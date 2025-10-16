#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge two sorted arrays;
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2 > len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(vector<int> &arr, int start, int end)
{
    // base case
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    // sort left part;
    mergeSort(arr, start, mid);

    // right part sort;

    mergeSort(arr, mid + 1, end);

    // merging
    merge(arr, start, end);
}

void printArr(vector<int> arr)
{
    for(int index = 0; index < arr.size(); index++){
        cout << arr[index] << " ";
    }
}

int main()
{
    vector<int> arr = {1, 4, 5, 6, 6, 5, 6, 23, 521, 42, 34, 543, 234};
    cout << "Previous array: ";
    printArr(arr);
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    cout << endl << "New array: ";
    printArr(arr);
    return 0;
}