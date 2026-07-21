#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool hasCycle(int src, int parent, vector<bool> &vis, vector<vector<int>> &graph)
    {
        queue<pair<int, int>> q;
        q.push({src, parent});
        vis[src] = 1;

        while (!q.empty())
        {
            src = q.front().first;
            parent = q.front().second;
            q.pop();

            for (int &neighbourNode : graph[src])
            {
                if (!vis[neighbourNode])
                {
                    vis[neighbourNode] = 1;
                    q.push({neighbourNode, src});
                }
                else if (neighbourNode != parent)
                    return 1;
            }
        }

        return 0;
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(V);

        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (hasCycle(i, -1, vis, graph))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++)
        cin >> edges[i][0] >> edges[i][1];

    Solution obj;

    if (obj.isCycle(V, edges))
        cout << "true";
    else
        cout << "false";

    return 0;
}
