#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V, E;
    vector<vector<int>> adj;
    Graph(int V)
    {
        this->V = V;
        adj = vector<vector<int>>(V);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

// Calculate distance between two vertex in a graph

int distanceBFS(Graph g, int src, int dest)
{
    vector<bool> visited(g.V, false);
    queue<pair<int,int>> q;
    q.push({src,0});
    visited[src] = true;
    while (!q.empty())
    {
        int u = q.front().first;
        int dist = q.front().second;
        q.pop();
        for (auto i: g.adj[u])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push({i,dist+1});
            }
            if(i==dest)
                return dist+1;
        }
    }
    return -1;
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    int src, dest;
    src = 0;
    dest = 4;
    cout << distanceBFS(g, src, dest);
    return 0;
}