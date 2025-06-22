// brute force 
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1;j < nums.size(); j++)
                if(nums[j] + nums[i] == target) {
                return {i, j};
            }
        }
        return {};
    }
};

// optimized solution using two pass hash table 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            int com = target - nums[i];
            if(hash.find(com) != hash.end() && hash[com] != i) {
                return {i , hash[com]};
            }
        }
        return {};
    }
};


// optimized solution using one pass hash table
// One-pass hash table solution
class Solution2 {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // Hash map to store number -> index mapping
        unordered_map<int, int> hash;
        
        // Iterate through the array once
        for (int i = 0; i < nums.size(); ++i) {
            // Calculate the complement needed to reach target
            int complement = target - nums[i];
            
            // If complement exists in hash map, we found our pair
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            
            // Store current number and its index in hash map
            hash[nums[i]] = i;
        }
        // If no solution exists, return empty vector
        return {};
    }
};