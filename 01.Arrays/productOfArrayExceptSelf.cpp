#include<bits/stdc++.h>
using namespace std;
void productFun(vector<int>&arr){
    int n=arr.size();
    vector<int>res(n,1);
    int prefix=1;
    int sufix=1;

    for(int i=0;i<n;i++){
        res[i]=prefix;
        prefix*=arr[i];
    }

    for(int i=n-1;i>=0;i--){
        res[i]*=sufix;
        sufix*=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=res[i];
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"original array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    productFun(arr);
    cout<<"product array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}