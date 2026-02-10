class Solution {
public:
    inline void bubbleSort(vector<int> &n) {
        for(int i = 0; i < n.size(); i++) {
            for(int j = 0; j < n.size() - 1; j++){
                if(n[i] < n[j]) {
                    swap(n[i], n[j]);
                }
            }
        }
    }
    void sortColors(vector<int>& nums) {
        bubbleSort(nums);
    }
};