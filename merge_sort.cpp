#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>merge(vector<int>&a, vector<int>&b, vector<int>& res){
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            res[k]=a[i];
            i++;k++;
        }
        else{
            res[k]=b[j];
            k++;j++;
        }
    }
    if(i==a.size()){
        while(j<b.size()){
            res[k]=b[j];
            k++;j++;
        }
    }
    if(j==b.size()){
        while(i<a.size()){
            res[k]=a[i];
            i++;k++;
        }
    }
    return res;
}
void mergesort(vector<int>&v){
    int n=v.size(); 
    // base case
    if(n==1) return ;

    int n1=n/2;
    int n2=n-n1;
    vector<int>a(n1),b(n2);

    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    
    for(int j=0;j<n2;j++){
        b[j]=v[j+n1];
    }

    // we will divide the vector until become single element
    mergesort(a);
    mergesort(b);
    merge(a,b,v);
}
int main(){
    int n;
    cout<<"enter the number:";
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<"printing theelements before sorting"<<endl;
    for(auto x:v){
        cout<<x<<" ";
    }
    mergesort(v);
    cout<<"printing the lement s after sorting:"<<endl;
    for(auto x:v){
        cout<<x<<" ";
    }
}