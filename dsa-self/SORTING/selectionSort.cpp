
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    vector<int> arr;
    int n;
    cout << "Give total numbers in array: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        arr.push_back(m);
    }
    selectionSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Array counts for test cases:
// 16 elements: 12 23 55 56 6 1 2 4 56 1234 35 2 231 4 12312
// 15 elements: 89 34 78 12 56 23 91 45 67 33 88 22 77 44 99 11
// 32 elements: 100 50 75 25 90 10 80 20 70 30 60 40 95 15 85 5 500 250 750 125 625 375 875 62 312 187 437 687 937 812 562 312
// 20 elements: 7 3 9 1 8 2 6 4 5 0 17 13 19 11 18 12 16 14 15 10
// 16 elements: 999 111 777 333 555 222 888 444 666 123 456 789 321 654 987 147
// 111 elements: 1024 512 256 128 64 32 16 8 4 2 1 2048 1536 768 384 192 96 48 24 12 6 3 1 0 1000 500 250 125 62 31 15 7 3 1 900 450 225 112 56 28 14 7 3 1 800 400 200 100 50 25 12 6 3 1 700 350 175 87 43 21 10 5 2 1 600 300 150 75 37 18 9 4 2 1 555 277 138 69 34 17 8 4 2 1 444 222 111 55 27 13 6 3 1 333 166 83 41 20 10 5 2 1 222 111 55 27 13 6 3 1 111 55 27 13 6 3 1