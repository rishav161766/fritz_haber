#include<iostream>
#include<vector>
#include<list>
using namespace std;
int v;// here v is the no of verices of this graph
vector<list<int> >graph;
void add_edge(int src,int dest,bool bidirn){
    graph[src].push_back(dest);
        if(bidirn==true){    
            graph[dest].push_back(src);
        }
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto ele:graph[i]){
            cout<<ele<<",";
        }
        cout<<"\n";
    }
}
int main(){
    // here we represnt the graph as adjacency list or array of linkedlist approach
    cout<<"enter the number of vertices: ";
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cout<<"enter the edges number :";
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false);
    }
    display();
    return 0;

}