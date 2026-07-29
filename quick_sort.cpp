#include<iostream>
#include<algorithm>
using namespace std;
int partition(int arr[],int si,int ei){
    // here we will asume any element as pivot and sort the array on basis of that
    int pivot=arr[(si+ei)/2];  
    int count=0;
    for(int i=si;i<=ei;i++){
        if(i==(si+ei)/2) continue;
        if(arr[i]<=pivot) count++;
    }    
        int pivotindx=count+si;
        swap(arr[(si+ei)/2],arr[pivotindx]);
        int i=si,j=ei;
        while(i<pivotindx && j>pivotindx){
            if(arr[i]<pivot) i++;
            if(arr[j]>pivot) j--;
            if(arr[i]>pivot and arr[j]<pivot) {
                swap(arr[i],arr[j]);
                i++;j--;
            }
        }
    return pivotindx;
}
void quicksort(int arr[],int si,int ei){
    if(si>=ei) return;
    int pi= partition(arr,si,ei);
    quicksort(arr,si,pi-1);
    quicksort(arr,pi+1,ei);

}
int main(){
    int arr[]={5,1,7,2,3,4,6,8,-8};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"printing the array before sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    quicksort(arr,0,n-1);// here we sending the arr with its starting and ending vertex
    cout<<endl<<"printing the array after sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}