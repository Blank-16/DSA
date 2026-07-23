class Solution {
public:
    int numSquares(int n) {
        if(n <= 0) return 0;

        static vector<int> count({0});

        while(count.size() <= n) {
            int m = count.size();
            int countSq = INT_MAX;
            for(int i = 1; i*i <= m; i++){
                countSq = min(countSq, count[m-i*i] + 1);
            }
            count.push_back(countSq);
        }
        return count[n];
    }
};