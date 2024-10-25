#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_ARRAY_LENGTH = 100;

void merge_descending(char arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;     // Size of the right subarray

    char leftArr[MAX_ARRAY_LENGTH];
    char rightArr[MAX_ARRAY_LENGTH];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr
    int i = 0;    // Initialindex of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (leftArr[i] >= rightArr[j])
        { // Change to >= for descending order
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if there are any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if there are any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSortDescending(char arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Avoid overflow

        // Sort first and second halves
        mergeSortDescending(arr, left, mid);
        mergeSortDescending(arr, mid + 1, right);

        // Merge the sorted halves
        merge_descending(arr, left, mid, right);
    }
}

int main()
{
    int n;
    cout << "Give array size: ";
    cin >> n;

    char arr[MAX_ARRAY_LENGTH];
    cout << endl << "Give array elements: ";
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSortDescending(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
