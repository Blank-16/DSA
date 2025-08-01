
from typing import List

class Solution:
    def threeSum(self , nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        for i , a in enumerate(nums):
            if i > 0  and a == nums[i - 1]:
                continue
            
            left , right = i+1 , len(nums) - 1
            while left < right:
                threeSum = a + nums[left] + nums[right]
                if threeSum > 0:
                    right -= 1
                elif threeSum < 0:
                    left += 1
                else:
                    res.append([a, nums[left], nums[right]])
                    left += 1
                    while nums[left] == nums[left - 1] and left < right:
                        left += 1
        return res
                    

if __name__ == "__main__":
    solution = Solution()
    test_cases = [
        [-1, 0, 1, 2, -1, -4],
        [0, 0, 0],
        [1, -1, -1, 0]
    ]
    
    for nums in test_cases:
        print(f"Input: {nums}")
        print(f"Output: {solution.threeSum(nums)}\n")

    
