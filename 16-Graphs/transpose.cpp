//always for a directed graph

#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>arr[],int start,int end){
    arr[start].push_back(end);
}
void displayGraph(vector<int>ans[],int V){
    for(int i=0;i<V;i++){
        cout<<i<<"->";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
void transposeGraph(vector<int>adj[],vector<int>transpose[],int V){
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            addEdge(transpose,adj[i][j],i);
        }
    }
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
    vector<int>transpose[V];
    transposeGraph(adj,transpose,V);
    displayGraph(transpose,V);
    return 0;
}