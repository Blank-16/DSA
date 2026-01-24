class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int width = j - i;
                int currHeight = min(height[i], height[j]);
                int area = width * currHeight;
                maxWater = max(maxWater, area);
            }
        }
        return maxWater;
    }
};

// traversing entire loop one by one and checking each value 
// results in tle 


// two pointer approach

class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int currHeight = min(height[left], height[right]);
            int area = width * currHeight;
            maxWater = max(maxWater, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};


class Optimised 
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right)
        {
            int width = right - left;

            if (height[left] < height[right])
            {
                int h = height[left];
                maxWater = max(maxWater, h * width);

                while (left < right && height[left] <= h)
                {
                    left++;
                }
            }
            else
            {
                int h = height[right];
                maxWater = max(maxWater, h * width);

                while (left < right && height[right] <= h)
                {
                    right--;
                }
            }
        }
        return maxWater;
    }
};