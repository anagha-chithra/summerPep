#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>findMat(int V,vector<vector<int>>&edges){
    vector<vector<int>>mat(V,vector<int>(V,0));

    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        mat[u][v]=1;
    }
    return mat;
}
int main(){
    int V;
    cin>>V;
    int e;
    cin>>e;

    vector<vector<int>>edges(e,vector<int>(2));
    for(int i=0;i<e;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<vector<int>>adj=findMat(V,edges);

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}