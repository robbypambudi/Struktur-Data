#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N];
vector<int> newAdj[N];
bool flag = false;
void dfsUtil(int src, int v, int n, vector<bool> vis)
{
    vis[src] = true;

    if (v == n)
    {
        flag = true;
    }
    if (flag)
        return;
    for (auto u : newAdj[src])
    {
        if (!vis[u])
        {
            dfsUtil(u, v + 1, n, vis);
        }
    }
}

void dfs(int node)
{

    vector<bool> visited;
    set<int> cek[node];
    for (int i = 0; i < node; i++)
    {
        for (auto u : adj[i])
        {
            for (auto v : adj[u])
            {
                if (cek[i].find(v) != cek[i].end())
                    continue;

                newAdj[i].push_back(v);
                cek[i].insert(v);
            }
        }
        visited.push_back(false);
    }

    int parent;

    for (int i = 0; i < node; i++)
    {
        dfsUtil(i, 0, node - 1, visited);

        // reset visited to false
        for (int i = 0; i < node; i++)
            visited[i] = false;
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void insertEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<int> cek;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        insertEdge(u, v);
        cek.push_back(u);
    }

    dfs(node);

    return 0;
}