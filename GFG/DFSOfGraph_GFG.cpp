class Solution {
  public:
  void check(vector<vector<int>>& adj,vector<int>&ans,int index,vector<bool>&visited){
      ans.push_back(index);
      for(auto c:adj[index]){
          if(!visited[c]){
              visited[c]=true;
              check(adj,ans,c,visited);
          }
      }
      
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>ans;
        vector<bool>visited(n,false);
        
        visited[0]=true;
        check(adj,ans,0,visited);
        
        return ans;
    }
};
