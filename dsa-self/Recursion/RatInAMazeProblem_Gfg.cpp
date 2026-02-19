#include <bits/stdc++.h>
using namespace std;

// 1 -> allowed path for rat to go
// 2 -> not allowed path for rat to go 
// need to move from source -> destination 
// movement options up, down, left, right 


bool isSafe(int x , int y, int n, vector<vector<int>> &visited, vector<vector<int>> &m){
  if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1){
    return true;
  }
  else {
    return false;
  }
}

void solve(vector<vector<int>> &m , int n, vector<string> &ans, int x, int y, vector<vector<int>> &visited, string path) {
  // base case;
  // reached x , y here

  if(x == n-1 && y == n-1) {
    ans.push_back(path);
    return;
  }

  visited[x][y] = 1;
  
  // 4 choices -  D, L , R, U

  // down;
  int newx = x + 1;
  int newy = y;
  if(isSafe(newx, newy, n, visited, m)) {
    path.push_back('D');
    solve(m, n, ans, newx, newy, visited, path);
    path.pop_back();
  }

  // left;
  newx = x;
  newy = y - 1;
  if(isSafe(newx, newy, n, visited, m)) {
    path.push_back('L');
    solve(m, n, ans, newx, newy, visited, path);
    path.pop_back();
  }
  // right
  newx = x;
  newy = y + 1;
  if(isSafe(newx, newy, n, visited, m)) {
    path.push_back('R');
    solve(m, n, ans, newx, newy, visited, path);
    path.pop_back();
  }

  // up 
  newx = x - 1;
  newy = y;
  if(isSafe(newx, newy, n, visited, m)) {
    path.push_back('U');
    solve(m, n, ans, newx, newy, visited, path);
    path.pop_back();
  }

  visited[x][y]= 0;
}

vector<string> func(vector<vector<int>> &m , int n){

  vector<string> ans;
  if(m[0][0] == 0) return ans;

  int srcX = 0;
  int srcY = 0;

  vector<vector<int>> visited = m;
  // initialise with 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++){
      visited[i][j] = 0;
    }
  }
  
  string path = "";
  solve(m , n, ans, srcX, srcY, visited, path);
  sort(ans.begin(), ans.end());
  return ans;
}



// gfg new code;

class Solution {
  public:
  
    bool isSafe(int x, int y, int n,
                vector<vector<int>>& maze,
                vector<vector<int>>& visited) {
        
        return (x >= 0 && x < n &&
                y >= 0 && y < n &&
                visited[x][y] == 0 &&
                maze[x][y] == 1);
    }
    
    
    void solve(vector<vector<int>>& maze,
               int n,
               vector<string>& ans,
               int x, int y,
               vector<vector<int>>& visited,
               string path) {
        
        // Base case
        if(x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        // Down
        if(isSafe(x+1, y, n, maze, visited)) {
            solve(maze, n, ans, x+1, y, visited, path + 'D');
        }
        
        // Left
        if(isSafe(x, y-1, n, maze, visited)) {
            solve(maze, n, ans, x, y-1, visited, path + 'L');
        }
        
        // Right
        if(isSafe(x, y+1, n, maze, visited)) {
            solve(maze, n, ans, x, y+1, visited, path + 'R');
        }
        
        // Up
        if(isSafe(x-1, y, n, maze, visited)) {
            solve(maze, n, ans, x-1, y, visited, path + 'U');
        }
        
        visited[x][y] = 0;  // Backtrack
    }
    
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
        int n = maze.size();
        vector<string> ans;
        
        if(n == 0 || maze[0][0] == 0)
            return ans;
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        solve(maze, n, ans, 0, 0, visited, "");
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
