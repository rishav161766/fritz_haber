#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int>v={3,1,2,5,4,6,2,3};
    int n=v.size();
    vector<int>nge(n);
    stack<int>st;
    nge[n-1]=-1;
    st.push(v[n-1]);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && st.top()<=v[i]){
            st.pop();
        }
        if(st.size()==0) nge[i]=-1;
        else nge[i]=st.top();
        st.push(v[i]);
    }

    for(int i=0;i<nge.size();i++){
        cout<<nge[i]<<" ";
    }
}