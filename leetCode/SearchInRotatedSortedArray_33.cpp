class Solution {
public:

    /*
        we are first searching the pivot point;
        after we find the pivot point at which the array is rotated;
        we apply binary search in both direction from the pivot point;
        to left and to right;
        if pivot == -1 which is basically it's a sorted array;
        then we simply apply binary search;
    */


    int searchPivot(vector<int> &arr) {
        int l=0, r = arr.size() - 1;
        while(l < r) {
            int mid = (l + r)/2;
            if(arr[mid] > arr[r]){
                l = mid+1;
            }else {
                r = mid;
            }
        }
        return l;
    }

    int binarySearch(vector<int> &arr, int l, int r, int k) {
        int mid = l + (r-l)/2;
        if( l > r ) return -1;
        if(arr[mid] == k) return mid;
        if(arr[mid] < k) {
            return binarySearch(arr, mid + 1, r, k);
        }
        if(arr[mid] > k) {
            return binarySearch(arr, l , mid-1, k);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int i = searchPivot(nums);
        if( i == -1) {
            return binarySearch(nums, 0, nums.size() - 1, target);
        } else {
            int num = binarySearch(nums, 0, i - 1, target);
            if(num == -1){
                num = binarySearch(nums, i, nums.size()-1, target);
            }
            return num;
        }
    }

};


class Solution1 {
    public:
    int search(vector<int> &nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) 
                return i;
        }
        return -1;
    }
};