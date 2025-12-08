#include <bits/stdc++.h>

class Solution
{
public:
    int countOdds(int low, int high)
    {
        return (high + 1) / 2 - (low / 2);
    };

    int firstAttempt(int low, int high)
    {
        int count = 0;
        for (int i = low; i <= high; i++)
        {
            if (i % 2 != 0)
            {
                count++;
            }
        }
        return count;
    }
};