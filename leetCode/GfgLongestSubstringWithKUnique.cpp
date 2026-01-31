class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        // code here
        // int n = s.size();
        // unordered_map<char, int> freq;

        // int left = 0, maxLen = -1;

        // for (int right = 0; right < n; right++) {
        //     freq[s[right]]++;

        //     // Shrink window if distinct characters exceed k
        //     while (freq.size() > k) {
        //         freq[s[left]]--;
        //         if (freq[s[left]] == 0) {
        //             freq.erase(s[left]);
        //         }
        //         left++;
        //     }

        //     // If window has exactly k distinct characters
        //     if (freq.size() == k) {
        //         maxLen = max(maxLen, right - left + 1);
        //     }
        // }

        // return maxLen;
        int n = s.size();
        vector<int> freq(26, 0);

        int left = 0;
        int distinctCount = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++)
        {
            // Add right character
            if (freq[s[right] - 'a'] == 0)
                distinctCount++;
            freq[s[right] - 'a']++;

            // Shrink window if distinct > k
            while (distinctCount > k)
            {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinctCount--;
                left++;
            }

            // Update answer when exactly k distinct
            if (distinctCount == k)
            {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};