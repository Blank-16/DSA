class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n=arr.size();
        int count=1;
        vector<vector<int>>ans;
        priority_queue<int>pq;
        for(int i=0;i<n;){
            while(i<n && pq.size()<count){
                pq.push(-1*arr[i]);
                i++;
            }
            vector<int>ds;
            while(!pq.empty()){
                ds.push_back(-1*pq.top());
                pq.pop();
            }
            ans.push_back(ds);
            count=(count<<1);
        }
        return ans;
    }
};
