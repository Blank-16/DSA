/*
 * Brute Force
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int left = 0, right = k - 1;
        do {
            int maxim = *max_element(nums.begin() + left, nums.begin() + right + 1);
            ans.push_back(maxim);
            left++;
            right++;
        } while((right < nums.size()));

        return ans;
    }
};


/*
 * double ended queue
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        deque <int> q; //double ended queue, this is for storing the indices
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(!q.empty() && q.front() == i - k) 
            {
                q.pop_front();   //Ensuring that the size of the window doesn't exceeds k
            }
            while(!q.empty() && nums[q.back()] < nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
            if(i >= k - 1)
            {
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
