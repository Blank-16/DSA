class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int m = -1;
        vector<int> a;
        for(auto n : capacity) {
            if(n >= itemSize) {
                a.push_back(n);
            }
        }
        if(a.empty()) return -1;
        m = *min_element(a.begin(), a.end());
        int index = 0;
        for(int i = 0; i < capacity.size(); i++) {
            if(capacity[i] == m) {
                index = i;
                break;
            }
        }
        return index;
    }
};
