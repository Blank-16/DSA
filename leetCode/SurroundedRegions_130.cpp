class Solution {
public:
     void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        int n=board.size();
        int m=board[0].size();

        vis[row][col]=1;

        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && board[nrow][ncol]=='O' && vis[nrow][ncol]==0) 
                    dfs(nrow,ncol,board,vis);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool isboundary=(i==0 || j==0 || i==n-1 || j==m-1);
                if(isboundary && vis[i][j]==0 && board[i][j]=='O')
                    dfs(i,j,board,vis);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};
