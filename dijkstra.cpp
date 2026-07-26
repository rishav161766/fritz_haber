#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;
vector<list<pp> >graph;

void add_edge(int src,int dest,int wt){
    graph[src].push_back({dest,wt});
    graph[dest].push_back({src,wt});
}

unordered_map<int,int> dijkstra(int src,int n){
    priority_queue<pp,vector<pp>,greater<pp> >pq;
    unordered_set<int>vis;
    vector<int>via(n+1);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[i]=INT_MAX;

    }
    pq.push({0,src});
    mp[src]=0;
    while(!pq.empty()){
        pp curr=pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
        for(auto neighbour:graph[curr.second]){
            if(!vis.count(neighbour.first) and mp[neighbour.first]>mp[curr.second]+neighbour.second){
                pq.push({mp[curr.second]+neighbour.second,neighbour.first});
                via[neighbour.first]=curr.second;
                mp[neighbour.first]=mp[curr.second]+neighbour.second;
            }
        }
    }
    return mp;
}
int main(){
    int n,m;
    cout<<"enter the vertices and edges: ";
    cin>>n>>m;
    graph.resize(n,list<pp>());
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    int src;
    cout<<"enter the source vertex: ";
    cin>>src;
    unordered_map<int,int> sp=dijkstra(src,n);
    for(auto p:sp){
        cout<<p.first<<" "<<p.second<<"\n";
    }
    int dest;
    cout<<"enter the destination point: ";
    cin>>dest;
    cout<<sp[dest]<<"\n";
    return 0;
}