
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Solution1(int n)
    {
        int count = 0;
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                for (int c = 1; c <= n; c++)
                {
                    if (a * a + b * b == c * c)
                        count++;
                }
            }
        }
        return count;
    }

    int Solution2(int n)
    {
        int count = 0;

        // Iterate through all possible values for the hypotenuse 'c'
        for (int c = 1; c <= n; ++c)
        {
            int target = c * c;
            int left = 1;
            int right = c - 1;

            // Two pointers approach to find a^2 + b^2 = c^2
            while (left < right)
            {
                int sum = left * left + right * right;

                if (sum == target)
                {
                    count += 2; // Add 2 because (a,b,c) and (b,a,c) are distinct
                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++; // Sum is too small, increase the smaller number
                }
                else
                {
                    right--; // Sum is too big, decrease the larger number
                }
            }
        }

        return count;
    }

    int EuclidsSolution(int n)
    {
        int res = 0;
        for (int u = 2; u <= sqrt(n); u++)
        {
            for (int v = 1; v < u; v++)
            {
                if (~(u - v) & 1 || gcd(u, v) != 1)
                    continue;
                int c = u * u + v * v;
                if (c > n)
                    continue;
                res += (n / c) << 1;
            }
        }
        return res;

        // link :       https://leetcode.com/problems/count-square-sum-triples/solutions/7399093/euclids-formula-onn-time-o1-space-comple-5u6c
    }
};