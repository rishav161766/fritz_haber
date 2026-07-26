#include<iostream>
#include<vector>
using namespace std;
int minimum(vector<int>&v,int lo,int hi){
    // only one element
    if(lo==hi){
        return v[lo];
    }
    // only two element
    if(hi==lo+1){
        if(v[lo]<v[hi]) return v[lo];
        else return v[hi];
    }
    int mid=(hi+lo)/2;
    int leftmin=minimum(v,lo,mid);
    int rightmin=minimum(v,mid+1,hi);

    if(leftmin<rightmin) return leftmin;
    else return rightmin;
}
int maximum(vector<int>&v,int lo,int hi){
    // only one element
    if(lo==hi) return v[hi];
    // twoelement present
    if(lo+1==hi){
        if(v[lo]>v[hi]) return v[lo];
        else return v[hi];
    }

    int mid=lo+(hi-lo)/2;
    int leftmax=maximum(v,lo,mid);
    int rightmax=maximum(v,mid+1,hi);

    if(leftmax<rightmax) return rightmax;
    else return leftmax;
}
int main(){
    vector<int>v={9,6,4,7,3,5,1,8};
    int n=v.size();
    cout<<"the minimum element is:"<<minimum(v,0,n-1)<<endl;
    cout<<"the maximum element is:"<<maximum(v,0,n-1);

}