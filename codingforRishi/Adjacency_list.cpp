#include<bits/stdc++.h>
using namespace std;
int v;
vector<list<int> >graph;

void add_edge(int src,int dest,bool bidirn){
    graph[src].push_back(dest);
    if(bidirn==true){
        graph[dest].push_back(src);
    }
}    

void display(){
    for(int i=0;i<graph.size();i++){
        for(auto ele:graph[i]){
            cout<<i<<" ->";
            cout<<ele<<", ";
        }
        cout<<"\n";
    }
}
int main(){
    cout<<"enter the vertices number:";
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cout<<"enter the number of edges: ";
    cin>>e;
    while(e--){
        int s,d;
        cout<<"enter start and ending point: ";
        cin>>s>>d;
        add_edge(s,d,true);
    }
    display();
}