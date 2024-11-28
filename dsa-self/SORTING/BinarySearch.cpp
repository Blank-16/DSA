#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>a, int beg, int end, int val)
{
    int mid;
    if (end >= beg)
    {
        mid = (beg + end) / 2;
        /* if the item to be searched is present at middle */
        if (a[mid] == val)
        {
            return mid + 1;
        }
        /* if the item to be searched is smaller than middle, then it can only be in left subarray */
        else if (a[mid] < val)
        {
            return binarySearch(a, mid + 1, end, val);
        }
        /* if the item to be searched is greater than middle, then it can only be in right subarray */
        else
        {
            return binarySearch(a, beg, mid - 1, val);
        }
    }
    return -1;
}

void PrintArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr;
    for (int i = 0; i < 1000; i++)
    {
        arr.push_back(rand() % 1000);
    }
    sort(arr.begin(), arr.end());
    int target;
    cout << "Give target: ";
    cin >> target;
    
    binarySearch(arr, 0, arr.size() - 1 , target);
    return 0;
}