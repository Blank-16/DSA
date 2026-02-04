class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() ==  1) return 0;
        int max = INT_MIN;
        int count;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max) {
                 max = nums[i];
                 count = i;
            }
        }
        return count;
    }
};


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;        
    }
};



// Step by Step Algorithm
// Step 1: Initialize the Search Range
// left = 0
// right = len(nums) - 1
// Explanation: We start by defining two pointers, left and right, which represent the search boundaries. The left pointer is set to the beginning of the array (0), and the right pointer is set to the last index (len(nums) - 1).
// Purpose: This initialization sets up the boundaries for our binary search.
// Step 2: Perform Binary Search Until the Search Range Collapses
// while left < right:
// Explanation: This loop will continue as long as left is less than right. The goal is to keep narrowing down the search range until left equals right, indicating that we have found a peak element.
// Purpose: It ensures that we systematically reduce the search space using binary search.
// Step 3: Calculate the Midpoint
// mid = (left + right) // 2
// Explanation: The midpoint of the current search range is calculated using the formula (left + right) // 2. This formula gives us the middle index of the current search space.
// Purpose: This mid index helps us decide whether to move the left or right pointer to narrow down the search.
// Step 4: Compare the Midpoint with its Right Neighbor
// if nums[mid] > nums[mid + 1]:
//     right = mid
// Explanation: We check if the element at the mid index is greater than its next element (nums[mid + 1]).
// Condition: If nums[mid] is greater, it indicates that a peak element might be to the left side, including the mid index itself.
// Action: Set the right pointer to mid. This shrinks the search space to the left half of the array.
// Purpose: This comparison tells us that we’re in the descending part of the array, and a peak lies somewhere on the left side (including mid).
// Step 5: Move the Left Pointer Otherwise
// else:
//     left = mid + 1
// Explanation: If nums[mid] is not greater than nums[mid + 1], it means that we are in the ascending part of the array.
// Condition: There must be a peak element on the right side of the mid index.
// Action: Move the left pointer to mid + 1, excluding the mid index and focusing on the right half.
// Purpose: This ensures that the search moves in the direction of an increasing trend, which will eventually lead to a peak.
// Step 6: Return the Index of the Peak Element
// return left
// Explanation: When the while loop ends, left and right will point to the same index, which is a peak element.
// Purpose: Return the left index, which is the position of one of the peak elements in the array.