#include<iostream>
#include<vector>
#include<list>
using namespace std;
int v;// here v is the no of verices of this graph
vector<list<pair<int,int> > >graph;
void add_edge(int src,int dest,int wt,bool bidirn){
    graph[src].push_back({dest,wt});
        if(bidirn==true){    
            graph[dest].push_back({src,wt});
        }
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto ele:graph[i]){          
            cout<<"("<<ele.first<<" "<<ele.second<<")"<<",";
        }
        cout<<"\n";
    }
}
int main(){
    // here we represnt the graph as adjacency list or array of linkedlist approach
    cout<<"enter the number of vertices: ";
    cin>>v;
    graph.resize(v,list<pair<int,int> >());
    int e;
    cout<<"enter the edges number :";
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt,false);
    }
    display();
    return 0;

}