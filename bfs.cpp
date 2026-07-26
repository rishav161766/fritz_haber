#include<bits/stdc++.h>
using namespace std;
int v;
vector<list<int> >graph;
unordered_set<int>visited;
vector<vector<int> >result;

void add_edge(int src,int dest,bool bidirn){
    graph[src].push_back(dest);
    if(bidirn){
        graph[dest].push_back(src);
    }
}

void bfs(int src,vector<int> &dist){
    queue<int>q;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src]=0;
    visited.insert(src);
    q.push(src);
    while(!q.empty()){
        int curr=q.front();
        cout<<curr<<" ";
        q.pop();
        for(auto neighbour: graph[curr]){
            if(!visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour]=dist[curr]+1;
            }
        }
    }
}
int main(){
    cout<<"enter the number of edges: ";
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cout<<"enter the numer of edges: ";
    cin>>e;
    visited.clear();
    while(e--){
        int s,d;
        cout<<"enter starting and ending point: ";
        cin>>s>>d;
        add_edge(s,d,true);
    }
    int x;
    cout<<" starting point: ";
    cin>>x;
    vector<int>dist;
    bfs(x,dist);
    cout<<endl<<"path to traverse every node with hminimum distance: ";
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}