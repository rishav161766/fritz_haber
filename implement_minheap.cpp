#include<iostream>
#include<algorithm>
using namespace std;
class minheap{
    public:
    int idx;
    int arr[50];
    minheap(){
        idx=1;
    }
    int top(){
        return arr[1];
    }
    void push(int x){
        arr[idx]=x;
        int i=idx;// we mark the index with i amd increament idx 
        idx++;
        // swapping of i with parent till i==1
        while(i!=1){
            int parent=i/2;
            if(arr[i]<arr[parent]){
                swap(arr[i],arr[parent]);
            }
            else break;
            i=parent;
        }
    }
    int size(){
        return idx-1;
    }
    void pop(){
        idx--;
        arr[1]=arr[idx];
        // rearrangement
        int i=1;
        while(true){
            int l=2*i;
            int r=2*i+1;
            if(l>idx-1) break;
            if(r>idx-1){
                if(arr[i]>arr[l]){
                    swap(arr[i],arr[l]);
                    i=l; 
                }
                break;
            }           
            if(arr[l]<arr[r]){
                if(arr[i]>arr[l]){
                    swap(arr[i],arr[l]);
                    i=l;
                }
                else break;
            }
            else{//arr[l] > arr[r]
                if(arr[i]>arr[r]){
                    swap(arr[i],arr[r]);
                    i=r;
                }
                else break;
            }
        }
    }
    void display(){
        for(int i=1;i<=idx-1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
/*for a node at i
    then,
    left child = 2*i;
    right child = 2*i+1;
    parent = i/2;
*/ 
minheap pq ;
pq.push(10);
pq.push(20);
pq.push(11);
pq.push(5);
cout<<pq.size()<<endl;
pq.display();
pq.pop();
cout<<pq.size()<<endl;
pq.push(23);
pq.push(47);
pq.display();
pq.pop();
pq.display();

int a=10;
int b=20;
int c=a+b;
cout<<"sum is :"<<c;
}