class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, stack<int>& st) {

        vis[node] = 1;

        for (int neigh : adj[node]) {
            if (!vis[neigh])
                dfs(neigh, adj, vis, st);
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(i, adj, vis, st);
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
