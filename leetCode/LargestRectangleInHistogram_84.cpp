
class Solution {
private:
    vector<int> nextSmallestElement(const vector<int> &nums,const int &n) {
        stack<int> s;
        s.push(-1);
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            int curr = nums[i];
            while (s.top() != -1 && nums[s.top()] >= curr) {
                s.pop();
            }
            res[i] = s.top();
            s.push(i);
        }
        return res;
    }

    vector<int> prevSmallestElement(const vector<int> &nums, const int &n) {
        stack<int> s;
        s.push(-1);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            while (s.top() != -1 && nums[s.top()] >= curr) {
                s.pop();
            }
            res[i] = s.top();
            s.push(i);
        }
        return res;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallestElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallestElement(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }
};


class SOL{
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int h = heights[st.top()];
                st.pop();
                int w;
                if (st.empty())
                    w = i;
                else
                    w = i - st.top() - 1;
                maxA = max(maxA, w * h);
            }
            st.push(i);
        }
        return maxA;
    }
};
