#include<iostream>
using namespace std;
int main(){
   // for counting flp bits we nedd to calculate how many bits are different
   // apply xor operation and count the setbits to calculate flip bits
   int x,y;
   cout<<"enter two number:";
   cin>>x>>y;
   cout<<__builtin_popcount(x^y);
}