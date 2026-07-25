#include<iostream>
#include<queue>
using namespace std;
int main(){
    // finding maximum element using minheap
        int nums[]={10,20,-4,6,18,2,105,118};
        int n=sizeof(nums)/sizeof(nums[0]);
        int k=3;
        priority_queue<int, vector<int> , greater<int> >pq;
            for(int i=0;i<n;i++){
                pq.push(nums[i]);
                if(pq.size()>k) pq.pop();
            }
            
            cout<<pq.top();
    
}