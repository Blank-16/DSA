#include <iostream>
#include <vector>

using namespace std;

// Warshall's algorithm to compute transitive closure
void warshallAlgorithm(vector<vector<int>> &adj, int N)
{
    // Apply the Warshall algorithm to compute transitive closure
    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    // Initialize the adjacency matrix
    vector<vector<int>> adj(N, vector<int>(N, 0));

    // Read the constraints (edges)
    for (int i = 0; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // There is a directed edge from u to v
    }

    // Run Warshall's algorithm to get the transitive closure
    warshallAlgorithm(adj, N);

    // Check for cycles: If there is a path from i to i, there's a cycle
    for (int i = 0; i < N; ++i)
    {
        if (adj[i][i] == 1)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    // If no cycles were found, the schedule is possible
    cout << "Yes" << endl;
    return 0;
}
