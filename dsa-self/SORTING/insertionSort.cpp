#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr) {
    int size = arr.size();
    for (int i = 1; i < size; ++i) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
        
    cout << "Original array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    insertionSort(arr);

    cout << "Sorted array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}