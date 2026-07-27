#include<bits/stdc++.h>
using namespace std;
int v;
vector<vector<int> >result;
unordered_set<int>visited;
vector<list<int> >graph;

void add_edge(int src,int dest,bool bidirn){
    graph[src].push_back(dest);
    if(bidirn){
        graph[dest].push_back(src);
    }
}

void dfs(int curr,int end,vector<int> &path){
    if(curr==end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto neighbour:graph[curr]){
        if(!visited.count(neighbour)){
            dfs(neighbour,end,path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}

void allpath(int src,int dest){
    vector<int>v;
    dfs(src,dest,v);
}
int main(){
    cout<<"enter the vertices number:";
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cout<<"enter the number of edges: ";
    cin>>e;
    visited.clear();
    while(e--){
        int s,d;
        cout<<"enter start and ending point: ";
        cin>>s>>d;
        add_edge(s,d,true);
    }
    int x,y;
    cout<<"enter the starting and ending vertex:";
    cin>>x>>y;
    allpath(x,y);
    for(auto path:result){
        for(auto el:path){
            cout<<el<<" ";
        }
        cout<<endl;
    }
}