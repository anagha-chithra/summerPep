#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int start,int end){
    adj[start].push_back(end);
    adj[end].push_back(start);
}
void displayGraph(vector<int>adj[],int V){
    for(int i=0;i<V;i++){
        cout<<i<<" -> ";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
void dfs(vector<int>adj[],vector<bool>&visited,vector<int>&res,int src){
    visited[src]=true;
    res.push_back(src);
    for(int x:adj[src]){
        if(!visited[x]){
            dfs(adj,visited,res,x);
        }
    }
}
vector<int>dfsTraversal(vector<int>adj[],int V){
    vector<bool>visited(V,false);
    vector<int>res;
    dfs(adj,visited,res,0);
    return res;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<int>adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        addEdge(adj,u,v);
    }
    displayGraph(adj,V);
    vector<int>ans=dfsTraversal(adj,V);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}