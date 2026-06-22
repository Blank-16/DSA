class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> f(26, 0);
        for(auto &c : text) {
            f[c - 'a']++;
        }
        return min({f[0], f[1], f['l' - 'a'] >> 1, f['o' - 'a'] >> 1, f['n'-'a']});
    }
};
