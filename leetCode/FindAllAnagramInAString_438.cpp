class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
            vector<int> result;
    if (s.length() < p.length()) return result;  // No anagrams if s is shorter than p
    
    // Frequency arrays for p and current window in s
    vector<int> pCount(26, 0), sCount(26, 0);
    
    // Initialize the frequency array for p
    for (char c : p) {
        pCount[c - 'a']++;
    }
    
    // Initialize the sliding window
    for (int i = 0; i < p.length(); i++) {
        sCount[s[i] - 'a']++;
    }
    
    // If the first window is an anagram
    if (sCount == pCount) {
        result.push_back(0);
    }

    // Slide the window
    for (int i = p.length(); i < s.length(); i++) {
        // Add the new character to the window
        sCount[s[i] - 'a']++;
        
        // Remove the old character from the window
        sCount[s[i - p.length()] - 'a']--;
        
        // If the current window is an anagram of p
        if (sCount == pCount) {
            result.push_back(i - p.length() + 1);
        }
    }
    
    return result;
    }
};