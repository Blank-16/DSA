class Solution {
  public:
    bool dfs(int node, vector<int> adj[],
             vector<bool>& visited,
             vector<bool>& pathVisited) {

        visited[node] = true;
        pathVisited[node] = true;

        for (int neighbor : adj[node]) {

            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, pathVisited))
                    return true;
            }

            else if (pathVisited[neighbor]) {
                return true;
            }
        }

        pathVisited[node] = false;

        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<int> adj[V];

        for (auto &edge : edges)
            adj[edge[0]].push_back(edge[1]);

        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, pathVisited))
                    return true;
            }
        }

        return false;
    }
};
