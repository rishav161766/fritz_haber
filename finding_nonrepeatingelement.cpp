#include<iostream>
using namespace std;
int main(){
    /*
        0^9= 0000^1001=1001=9
        so XOR follows commutative property
        if every element is repeating except one the the net result of xor is that element
    */
   int arr[]={4,4,1,3,2,3,5,1,2};
   int n=sizeof(arr)/4;
   int res=0;
   for(int i=0;i<n;i++){
    res=res^(arr[i]);
   }
   cout<<res;

}