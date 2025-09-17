#include <iostream>
using namespace std;

bool isPresent(int nums[], int num, int size)
{
    if(size == 0) return false;
    if(nums[0] == num) return true;
    else {
        isPresent(nums+1, num, size-1);
    }
    return false;
}

int main()
{
    int arr[] = {1, 3, 4, 2, 3, 1, 23, 313, 5, 12, 2, 4, 5, 12, 4, 2125, 23, 125, 21, 4, 12};
    int size = sizeof(arr)/sizeof(arr[0]); 
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << ((isPresent(arr, num, size)) ? "Present" : "Absent");
    return 0;
}