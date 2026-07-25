#include<iostream>
#include<queue>
using namespace std;
int main(){
    // finding kth smallest element
    // T.C. = O(k*logn)
   priority_queue<int,vector<int>,greater<int>>pq;
   pq.push(10); pq.push(20); pq.push(-4); pq.push(6); pq.push(18); pq.push(24); pq.push(105); pq.push(118); 
    int k;
    cout<<"enter the number:";
    cin>>k;
    for(int i=1;i<k;i++){
        pq.pop();
    }
   cout<<pq.top();//10 
    
}