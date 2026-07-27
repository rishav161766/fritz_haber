#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(pair<int,int>&p1,pair<int,int>&p2){
    double r1=(p1.first*1.0)/(p1.second*1.0);
     double r2=(p2.first*1.0)/(p2.second*1.0);
     return r1>r2;
}
double fractional_knapsack(vector<int>&p,vector<int>&w,int n,int c){
    vector<pair<int,int> >arr;
    for(int i=0;i<n;i++){
        arr.push_back({p[i],w[i]});
    }
    sort(arr.begin(),arr.end(),cmp);
    double result=0;
    for(int i=0;i<n;i++){
        if(arr[1].second<=c){
            result+=arr[1].first;
            c-=arr[1].second;
        }else{
            result+=(arr[i].first*1.0)/(arr[i].second*1.0)*c;
            c=0;
            break;
        }
    }
    return result;
}
int main(){
    vector<int>profit={60,100,120};
    vector<int>weights={10,20,30};
    int n=3;
    int w=50;
    cout<<fractional_knapsack(profit,weights,n,w)<<"\n";
    return 0;
}