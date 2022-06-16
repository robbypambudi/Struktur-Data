#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;                   // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort()
{
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
    int E, V;
    cin >> V >> E;
    n = V;
    adj.assign(V, vector<int>());
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    topological_sort();
    for (int i : ans)
        cout << i << " ";
    return 0;
}
