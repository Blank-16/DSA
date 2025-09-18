#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> arr, int start, int end, int key)
{
    int mid = start + (end - start) / 2;
    // base case
    // element not found
    if (start > end)
        return false;

    // element found
    if (arr[mid] == key)
        return true;

    if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, end, key);
    }
    else
    {
        return binarySearch(arr, start, mid - 1, key);
    }
}

int main()
{
    vector<int> arr = {1, 3, 4, 2, 3, 1, 23, 313, 5, 12, 2, 4, 5, 12, 4, 2125, 23, 125, 21, 4, 12};
    int size = arr.size();
    sort(arr.begin(), arr.end());
    bool val = binarySearch(arr, 0, size, 899);
    cout << (val ? "Present" : "Not present");

    return 0;
}