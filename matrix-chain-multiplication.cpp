#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
vector<vector<int> >dp;
int f(vector<int>&v,int i,int j){
    if( i==j or i+1==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(ans,f(v,i,k)+f(v,k,j)+v[i]*v[j]*v[k]);
    }
    return dp[i][j]=ans;
}
    
int main(){
    int n;
    cin>>n;
    vector<int>v(n,-1);// initialising a vetor with size n and each cell value -1
    dp.clear();
    dp.resize(1005,vector<int>(1000,-1));
    for(int i=0;i<n;i++){cin>>v[i];}
        cout<<f(v,0,n-1)<<"\n";
    
    
}