#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solution(vector<int> nums, int k)
    {
        return 1;
    }
};

int main()
{
    vector<int> arr = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    sort(arr.begin(), arr.end());
    for(auto n : arr) {
        cout << n << ", ";
    }
}
