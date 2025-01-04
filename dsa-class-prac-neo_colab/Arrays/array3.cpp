// You are using GCC
#include <bits/stdc++.h>
using namespace std;

void printArray(const vector<int> &arr) {
    for(auto i : arr)
    {
        cout << i << " ";
    }
}

void inputArr(vector<int> &arr, int n){
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a); 
    }
}
int main(){
    int n, m;
    vector<int> arr1, arr2, arr;
    cin >> n;
    inputArr(arr1, n);
    cin >> m;
    inputArr(arr2, m);
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(arr));
    printArray(arr);
}