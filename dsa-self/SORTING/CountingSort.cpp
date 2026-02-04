#include <bits/stdc++.h>
using namespace std;


void countingSort (vector<int> &arr) {
    if(arr.empty()) return;
    int maxVal = *max_element(arr.begin(), arr.end());

    // count array
    vector<int> count(maxVal + 1, 0);

    for(int x : arr) {
        count[x]++;
    }

    int index = 0;
    for(int i = 0; i <= maxVal; i++) {
        while(count[i]--) {
            arr[index++] = i;
        }
    }
}


// counting sort including negative numbers

void negNumCountingSort(vector<int> &arr)
{
    if (arr.empty())
        return;

    int minVal = *min_element(arr.begin(), arr.end());
    int maxVal = *max_element(arr.begin(), arr.end());

    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);

    for (int x : arr)
        count[x - minVal]++;

    int index = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i]--)
        {
            arr[index++] = i + minVal;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    countingSort(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}