#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int start,int end){
    adj[start].push_back(end);
    adj[end].push_back(start);
}
vector<int>bfs(vector<int>adj[],int V){
    vector<bool>visited(V,false);
    vector<int>ans;
    queue<int>q;
    int src=0;
    visited[src]=true;
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        ans.push_back(curr);
        for(int j=0;j<adj[curr].size();j++){
            if(!visited[adj[curr][j]]){
                visited[adj[curr][j]]=true;
                q.push(adj[curr][j]);
            }
        }
    }
    return ans;
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
    vector<int>ans=bfs(adj,V);
    for(int x:ans){
        cout<<x<<" ";
    }
}