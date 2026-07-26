#include<iostream>
using namespace std;
string decTobin(int n){
    string result="";
    while(n>0){
        if(n%2==0){
            result='0'+result;
        }
        else result='1'+result;
        n=n/2;
    }
    return result;
}
int main(){
    // if one bit is 1 then it's called set bits
    // for counting set bits first convert decimal to binary and then run a loop to count set bits
    // in c++ we have a builtin functoin to tell this
    cout<<__builtin_popcount(15);
   int n;
   cout<<"enter the number:";
   cin>>n;
   string k=decTobin(n);
   int count=0;
   for(int i=0;i<k.size();i++){
    if(k[i]=='1') count++;
   }
   cout<<count;
}
