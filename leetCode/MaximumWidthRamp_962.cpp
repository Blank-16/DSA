class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> right_max(n);

        right_max[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = max(nums[i], right_max[i + 1]);
        }

        int i = 0, j = 0;
        int result = 0;

        while (j < n) {
            if (nums[i] <= right_max[j]) {
                result = max(result, j - i);
                ++j;
            } else {
                ++i;
            }
        }

        return result;
    }
};

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int answer = 0, n = nums.size();
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty() || nums[i] > nums[st.top()])
                st.push(i);
        }
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                int j = st.top();
                st.pop();
                answer = max(answer, j - i);
            }
        }
        return answer;
    }
};
