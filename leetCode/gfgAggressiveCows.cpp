class Solution
{
public:
    bool canPlaceCows(vector<int> &stalls, int k, int dist)
    {
        int cows = 1; // place first cow
        int lastPos = stalls[0];

        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - lastPos >= dist)
            {
                cows++;
                lastPos = stalls[i];
                if (cows == k)
                    return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k)
    {
        // code here
        sort(stalls.begin(), stalls.end());

        int low = 1;
        int high = stalls.back() - stalls.front();
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid))
            {
                ans = mid;     // mid is feasible
                low = mid + 1; // try larger distance
            }
            else
            {
                high = mid - 1; // reduce distance
            }
        }
        return ans;
    }
};