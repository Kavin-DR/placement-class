//gfg Number of Connected Components

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[node] = true;
        for (int nei : adj[node]) 
        {
            if (!vis[nei]) 
            {
                dfs(nei, adj, vis);
            }
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V, false);
        int count = 0;
        for (int i = 0; i < V; i++) 
        {
            if (!vis[i]) 
            {
                dfs(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};
