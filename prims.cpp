#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;
vector<list<pp> >graph;

void add_edge(int src,int dest,int wt){
    graph[src].push_back({dest,wt});
    graph[dest].push_back({src,wt});
}

ll prims(int src,int n){
    priority_queue<pp, vector<pp>, greater<pp> >pq;
    unordered_set<int>vis;
    vector<int>par(n+1);
    unordered_map<int,int>mp;
    for(int i=1;i<=n;i++){
        mp[i]=INT_MAX;
    }
    pq.push({0,src});
    mp[src]=0;
    int totalcount=0;
    int result=0;
    while(totalcount<n && !pq.empty()){
        pp curr=pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        totalcount++;
        result+=curr.first;
        pq.pop();
        for(auto neighbour: graph[curr.second]){
            if(!vis.count(neighbour.first) and mp[neighbour.first]>neighbour.second){
                pq.push({neighbour.second,neighbour.first});
                par[neighbour.first]=curr.second;
                mp[neighbour.first]=neighbour.second;
            }
        }
    }
        return result;
}

int main(){
    int n,m;
    cout<<"enter number of vertices and edges:";
    cin>>n>>m;
    graph.resize(n+1,list<pp>() );
    while(m--){
        int u,v,w;
        cout<<"entet terminals and weight: ";
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    int src;
    cout<<"enter the source: ";
    cin>>src;
    cout<<prims(src,n);
    return 0;
}