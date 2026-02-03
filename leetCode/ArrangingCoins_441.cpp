class Solution1
{
public:
    int arrangeCoins(int n)
    {
        return (int)((-1LL + sqrtl(1 + 8LL * n)) / 2);
    }
};


class Solution
{
public:
    int arrangeCoins(int n)
    {
        int count = 0;
        int k = 1;
        int rows = 0;
        for (int i = 0; i < n; i++)
        {
            n -= i + 1;
            if (n < 0)
            {
                return rows;
            }
            else
            {
                rows++;
            }
        }
        return rows;
    }
};