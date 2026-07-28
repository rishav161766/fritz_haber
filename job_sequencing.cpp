#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class job{
    public:
    char id;
    int deadline;
    int profit;
};

bool cmp(job a,job b){// making this function to sort profits descending order
    return a.profit>b.profit;
}

int main(){
    int n;
    cout<<"enter the nubmer of jobs:";
    cin>>n;
    vector<job>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].id>>v[i].deadline>>v[i].profit;
    }
    sort(v.begin(),v.end(),cmp);

    // creating the maximum deadline
    int maxdeadline=0;
    for(int i=0;i<n;i++){
        maxdeadline=max(maxdeadline,v[i].deadline);
    }

    // creating the slotbox
    vector<char>slot(maxdeadline+1,'\0');
    int totalprofit=0;
    for(int i=0;i<n;i++){
        for(int j=v[i].deadline;j>=1;j--){
            if(slot[j]=='\0'){
                slot[j]=v[i].id;
                totalprofit+=v[i].profit;
                break;
            }
        }
    }
    cout<<"selected jobs: ";
    for(int i=1;i<=maxdeadline;i++){
        if(slot[i]!='\0'){
            cout<<slot[i]<<" ";
        }
    }
    cout<<endl<<"total profit: "<<totalprofit;
}