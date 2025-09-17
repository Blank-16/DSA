#include <iostream>
using namespace std;

auto getSum(int nums[], int size)
{
    if(size == 0) return 0;
    if(size == 1) return nums[0];

    return nums[0] + getSum(nums+1, size-1);
}

int main()
{
    int arr[] = {1, 2, 4, 6, 2, 3, 1, 5, 21, 4, 99, 1, 35, 12, 56};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Total sum of arr: " << getSum(arr, size);
    
    return 0;
}