#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    
       unordered_map<int, int> mp;
       vector<int> nums = { -3, 0, 1, -3, 1, 1, 1, -3, 10, 0 };

       for(int n: nums) mp[n]++;

       for(auto it: mp) {
              cout << it.second;
       }

       cout << endl;
       vector<int> ans;
       for(auto it: mp) {
              ans.push_back(it.second);
       }
        for(int i = 0; i < ans.size() - 1; i++) {
              if(ans[i] == ans[i+1]) return false;
        }      
        return true;
}