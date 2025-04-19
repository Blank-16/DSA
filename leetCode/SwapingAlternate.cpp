
#include <iostream>
using namespace std;

    
int main() {
    int n;
    cout << "Size of array: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array after swapping alternate elements: ";

    for(int i = 0; i < n - 1; i++){
        arr[i] = arr[i] ^ arr[i+1];
        arr[i+1] = arr[i] ^ arr[i+1];
        arr[i] = arr[i] ^ arr[i+1];
        i++;
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}