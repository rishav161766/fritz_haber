#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int find(vector<int>& parent,int a){
    return parent[a]=((parent[a]==a)? a :find(parent,parent[a]));
}

void unon(vector<int>&par, vector<int>&rank,int a,int b){
    a=find(par,a);
    b=find(par,b);
    if(a==b) return;// both holds same rank
    if(rank[a]>=rank[b]){
        rank[a]++;
        par[b]=a;
    }
    else{
        rank[b]++;
        par[a]=b;
    }
}

struct edge{
    int src, dest, wt;
};
bool cmp(edge e1,edge e2){
    return e1.wt<e2.wt;
}
ll kruskals(vector<edge> &ip, int n,int e){
    sort(ip.begin(),ip.end(),cmp);
    vector<int>parent(n+1);
    vector<int>rank(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    int edgecount=0;
    int i=0;
    ll ans=0;
    while(edgecount<n-1 && i<ip.size()){
        edge curr=ip[i];
        int srcpar=find(parent,curr.src);
        int destpar=find(parent,curr.dest);
        if(srcpar!=destpar){
            unon(parent,rank,srcpar,destpar);
            ans+=curr.wt;
            edgecount++;
        }
        i++;
    }
    return ans;
}
int main(){
    int n,e;
    cout<<"enter number of vertices and edges:";
    cin>>n>>e;
    vector<edge>v(e);
    for(int i=0;i<e;i++){
        cout<<"give every vertivces starting ending and edge value: ";
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskals(v,n,e);
 }