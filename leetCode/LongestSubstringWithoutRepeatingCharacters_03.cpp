class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> charIndexMap; // stores the last index of each character
        int maxLength = 0;
        int left = 0; // sliding window start

        for (int right = 0; right < s.size(); right++)
        {
            // If the character has been seen before and its index is >= left
            if (charIndexMap.find(s[right]) != charIndexMap.end() &&
                charIndexMap[s[right]] >= left)
            {
                left = charIndexMap[s[right]] + 1; // move left pointer to the right of the repeated character
            }

            charIndexMap[s[right]] = right;               // update the last seen index of the character
            maxLength = max(maxLength, right - left + 1); // update max length
        }

        return maxLength;
    }
};