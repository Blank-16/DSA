#include <bits/stdc++.h>
using namespace std;

string solve(const vector<int> &arr)
{
    int n = arr.size();
    vector<bool> occupied(n + 2, false);
    occupied[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        int seat = arr[i];
        if (!occupied[seat - 1] && !occupied[seat + 1])
        {
            return "NO";
        }
        occupied[seat] = true;
    }
    return "YES";
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}