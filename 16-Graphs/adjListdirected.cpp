#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>createGraph(int V,vector<vector<int>>&edges){
    vector<vector<int>>adj(V);

    for(auto it:edges){
        int u=it[0];
        int v=it[1];

        adj[u].push_back(v);
    }
    return adj;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>>edges(E,vector<int>(2));
    for(int i=0;i<E;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<vector<int>>adj=createGraph(V,edges);
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}