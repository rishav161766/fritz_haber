#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int binary_to_decimal(string &binary){
    int n=binary.size();
    int result=0;
    for(int i=n-1;i>=0;i--){
        char ch=binary[i];
        int num=ch-'0';
        result=result+num*(1<<(n-i-1));//pow(2,n-i-1);
    }
    return result;
}
int main(){
    string s;
    cout<<"enter the string";
    getline(cin,s);
    cout<<binary_to_decimal(s);
}