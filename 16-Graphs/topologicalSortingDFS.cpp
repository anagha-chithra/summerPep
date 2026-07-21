#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void getTopoSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>> &graph)
    {
        vis[src] = 1;

        for (int &neighbourNode : graph[src])
        {
            if (!vis[neighbourNode])
            {
                getTopoSort(neighbourNode, vis, s, graph);
            }
        }

        s.push(src);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(V);

        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<bool> vis(V, 0);
        stack<int> s;

        for (int node = 0; node < V; node++)
        {
            if (!vis[node])
            {
                getTopoSort(node, vis, s, graph);
            }
        }

        vector<int> ans;

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    vector<int> ans = obj.topoSort(V, edges);

    for (int node : ans)
    {
        cout << node << " ";
    }

    return 0;
}
