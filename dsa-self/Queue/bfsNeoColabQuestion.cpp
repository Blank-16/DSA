#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

// Function to add an undirected edge between src and dest
void add_edge(int adj[][100], int src, int dest)
{
    adj[src][dest] = 1; // Edge from src to dest
    adj[dest][src] = 1; // Since it's an undirected graph, add reverse edge
}

// BFS function to find the shortest path from src to dest
bool BFS(int adj[][100], int src, int dest, int v, int pred[], int dist[])
{
    // Initialize visited array, dist[], and pred[]
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX; // Initialize all distances as infinity
        pred[i] = -1;      // No predecessors initially
    }

    // Queue for BFS traversal
    queue<int> q;
    visited[src] = true;
    dist[src] = 0;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // Explore all the neighbors of u
        for (int i = 0; i < v; i++)
        {
            if (adj[u][i] == 1 && !visited[i])
            {
                visited[i] = true;
                dist[i] = dist[u] + 1; // Increment the distance
                pred[i] = u;           // Mark the predecessor
                q.push(i);

                // Stop if we reach the destination
                if (i == dest)
                {
                    return true; // Return true if destination is found
                }
            }
        }
    }

    return false; // Return false if no path exists between src and dest
}

// Function to print the shortest path from src to dest
void printShortestDistance(int adj[][100], int s, int dest, int v, int pred[], int dist[])
{
    // If destination is unreachable, print a message
    if (dist[dest] == INT_MAX)
    {
        cout << "No path exists from " << s << " to " << dest << endl;
        return;
    }

    // Print the shortest distance
    cout << "Shortest path length is: " << dist[dest] << endl;

    // Reconstruct the path from src to dest using the pred[] array
    vector<int> path;
    for (int i = dest; i != -1; i = pred[i])
    {
        path.push_back(i);
    }

    // Print the path in reverse order
    cout << "Path is: ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main()
{
    int v, e;
    cin >> v; // Number of vertices

    int adj[100][100] = {0}; // Adjacency matrix initialized to 0

    cin >> e; // Number of edges

    // Read edges and add to the adjacency matrix
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        add_edge(adj, src, dest);
    }

    int source, dest;
    cin >> source >> dest; // Read source and destination vertices

    int pred[v], dist[v];

    // Call BFS to compute shortest path
    if (BFS(adj, source, dest, v, pred, dist))
    {
        printShortestDistance(adj, source, dest, v, pred, dist);
    }
    else
    {
        cout << "No path exists from " << source << " to " << dest << endl;
    }

    return 0;
}
