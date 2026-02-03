class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];

        int water = 0;

        while(left < right) {
            if(leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax , height[right]);
                water += rightMax - height[right];
            }
        }
        return water;
    }
};


// Step by Step Algorithm

//     Initialize pointers and variables : Initialize two pointers left and right at the beginning and end of the height list respectively.Initialize variables left_max and right_max to store the maximum height encountered from the left and right sides respectively.Initialize a variable water to keep track of the total trapped water.left = 0 right = len(height) - 1 left_max = height[left] right_max = height[right] water = 0 Loop until pointers meet : Continue looping while left pointer is less than right pointer,

//      indicating there are still bars to process.while left < right : Check which side to move : Compare left_max and right_max heights.If left_max is less than right_max, move the left pointer to the right and update left_max.Otherwise, move the right pointer to the left and update right_max.if left_max < right_max : left += 1 left_max = max(left_max, height[left]) water += left_max - height[left] else : right -= 1 right_max = max(right_max, height[right]) water += right_max - height[right] Calculate trapped water :

//     Calculate the water trapped at the current position based on the difference between the maximum height and the current height.Accumulate this water amount to the water variable.Return total trapped water :

//     After the loop ends,
    
//     return the total trapped water accumulated in the water variable.
   
//     return water