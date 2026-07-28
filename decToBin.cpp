#include<iostream>
using namespace std;
string decimal_to_binary(int n){
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
    int n;
    cout<<"enter the number:";
    cin>>n;
    string k=decimal_to_binary(n);
    cout<<k;
}