// for ordered set and map we use the header file following
#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
    // syntax 
    set<int>s;// the functions are same for unordered
    s.insert(5);
    s.insert(3);
    for(auto x: s){
        cout<<x<<" ";
    }
    map<int,int>m;// the functions are same for unordered
    m[2]=31;
    m[1]=30;
    m[3]=32;
    cout<<endl;
    for(auto x: m){
        cout<<x.first<<" "<<x.second<<endl;
    }
    map<string,int>p;
    p.insert({"Rishav",19});
    p.insert({"Disha",20});
    p.insert({"Pausali",21});
    for(auto x: p){
        cout<<x.first<<" "<<x.second<<endl;
    }
}
