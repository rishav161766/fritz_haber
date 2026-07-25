#include<iostream>
#include<queue>
using namespace std;
int main(){
    // heaps are known as priority queue
    // it works as a chaluni lighter particles go through pores and heavier particles stay at top
    
    // NOTe:= always maxm element is present at top
    priority_queue<int>pq; // it indicate maxheap
    pq.push(30); pq.push(40); pq.push(50); pq.push(10); pq.push(20);
    // c++ by default makes maxheap
    cout<<pq.top()<<" "; //50
    pq.pop();
    cout<<pq.top();// 40

    /*
        top= O(1)
        push= O(logn)
        pop= O(logn)
    */
   // in minheap min elements is present on top
   priority_queue<int,vector<int>,greater<int>>pq; // it's minheap

}