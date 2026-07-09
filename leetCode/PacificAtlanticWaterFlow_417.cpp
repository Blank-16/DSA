class Solution {
public:

    void dfs(int n,int m,int row,int col,int dr[],int dc[],vector<vector<int>>& heights,vector<vector<bool>>&vis){

        vis[row][col]=true;
        for(int i =0;i<4;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr<0 || nc < 0 || nr >= n || nc >= m) continue ;
            if(vis[nr][nc] == true) continue ;
            if(heights[nr][nc] < heights[row][col]) continue ;
            dfs(n,m,nr,nc,dr,dc,heights,vis) ;
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        vector<vector<bool>> pacific_vis(n,vector<bool>(m,false)) ;
        vector<vector<bool>> atlantic_vis(n,vector<bool>(m,false)) ;

        for(int j=0;j<m;j++){
            dfs(n,m,0,j,dr,dc,heights,pacific_vis);
            dfs(n,m,n-1,j,dr,dc,heights,atlantic_vis) ;
        }

        for(int i = 0;i<n;i++){
            dfs(n,m,i,0,dr,dc,heights,pacific_vis) ;
            dfs(n,m,i,m-1,dr,dc,heights,atlantic_vis) ;
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic_vis[i][j] && pacific_vis[i][j]){
                    ans.push_back({i,j}) ;
                }
            }
        }
        return ans ;

    }
};
