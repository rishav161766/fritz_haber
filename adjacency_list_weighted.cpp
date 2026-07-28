#include<bits/stdc++.h>
using namespace std;
int v;
vector<list<pair<int,int>> >graph;

void add_edge(int src,int dest,int wt,bool bidirn){
    graph[src].push_back({dest,wt});
    if(bidirn==true){
        graph[dest].push_back({src,wt});
    }
}    

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" ->";
        for(auto ele:graph[i]){
            cout<<"("<<ele.first<<","<<ele.second<<")";
        }
        cout<<"\n";
    }
}
int main(){
    cout<<"enter the vertices number:";
    cin>>v;
    graph.resize(v,list<pair<int,int> >());
    int e;
    cout<<"enter the number of edges: ";
    cin>>e;
    while(e--){
        int s,d,wt;
        cout<<"enter start and ending point and weight: ";
        cin>>s>>d>>wt;
        add_edge(s,d,wt,true);
    }
    display();
}