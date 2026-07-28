// rotate the given array by k steps 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void reversepart(int i,int j,vector<int>&arr){
    
    // here we using double pointer method
    while(i<=j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;j--;
    }
}
int main(){
   // copy contents of array in another in reverse order
   vector<int>v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   v.push_back(4);
   v.push_back(5);
   v.push_back(6);
   v.push_back(7);
   for(int i=0;i<v.size();i++){
      cout<<v[i]<<" ";
   }
   reversepart(0,v.size()-1,v);
   cout<<endl;
   for(int i=0;i<v.size();i++){
      cout<<v[i]<<" ";
   }
}