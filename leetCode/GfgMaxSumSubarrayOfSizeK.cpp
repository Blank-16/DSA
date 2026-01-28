class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        // // code here
        // int l = 0 , r = k;
        // int sum = 0;
        // while(r <= arr.size()) {
        //     int temp = 0;
        //     for(int i = l; i < r; i++ ){
        //         temp += arr[i];
        //     }
        //     sum = max(temp, max);
        //     l++; r++;
        // }
        // return sum;

        // int n = arr.size();
        // if (k > n) return 0;

        // int windowSum = 0;
        // for (int i = 0; i < k; i++) {
        //     windowSum += arr[i];
        // }

        // int maxSum = windowSum;

        // for (int i = k; i < n; i++) {
        //     windowSum += arr[i] - arr[i - k];
        //     maxSum = max(maxSum, windowSum);
        // }

        // return maxSum;

        int windowSum = 0, maxSum = INT_MIN;

        for (int i = 0; i < arr.size(); i++)
        {
            windowSum += arr[i];

            // once window size exceeds k, shrink from left
            if (i >= k)
            {
                windowSum -= arr[i - k];
            }

            // window size is exactly k
            if (i >= k - 1)
            {
                maxSum = max(maxSum, windowSum);
            }
        }

        return maxSum;
    }
};