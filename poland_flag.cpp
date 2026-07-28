#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void display(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void poland(vector<int>&arr){
    int noz=0,noo=0;// noz count no of 0 and noo count no. of 1
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==0) noz++;
        else noo++;
    }
   
    for(int i=0;i<n;i++){
        if(i<noz) arr[i]=0;
        else arr[i]=1;
    }
}
// another method usign double pointer approach
void sort1(vector<int>&v){
    int n=v.size();
    int i=0,j=n-1;
    while(i<j){
    if(v[i]==0) i++;
    else if(v[j]==1) j--;
    //if(i>j) break;
      else if(v[i]==1 && v[j]==0) {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    
    
}
int main(){
    // method 1:= two pass
    vector<int>v2;
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(1);
    display(v2);
    sort1(v2);
    display(v2);   
}
