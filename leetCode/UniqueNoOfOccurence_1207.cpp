
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        for(int n : arr) 
            mp[n]++;
        vector<int> ans;
        for(auto n: mp) {
            ans.push_back(n.second);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size() - 1; i++) {
              if(ans[i] == ans[i+1]) return false;
        }    
        return true;
    }
};


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Count occurrences of each number
        unordered_map<int, int> occurrenceMap;
        for (int num : arr) {
            occurrenceMap[num]++;
        }

        // Step 2: Check if all occurrence counts are unique using a set
        unordered_set<int> uniqueCounts;
        for (auto& entry : occurrenceMap) {
            uniqueCounts.insert(entry.second);
        }

        return uniqueCounts.size() == occurrenceMap.size();
    }
};
