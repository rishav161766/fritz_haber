#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>>pq; // syntax of minheap is  priority_queue <datatype,container,comparator> variable name
    pq.push(10);
    pq.push(25);
    pq.push(-6);
    pq.push(81);
    cout<<pq.top();// output:= -6
    pq.pop();
    cout<<pq.top();//10 
 priority_queue<float,vector<float>,greater<float>>ab; // minheap of float type
}