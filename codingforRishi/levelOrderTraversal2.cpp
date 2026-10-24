#include<bits/stdc++.h>
#include<queue>
using namespace std;
class node{
    public:
    int val;
    node* left;
    node* right;
    node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
node* construct(int arr[],int n){
    queue<node*>q;
    node* root=new node(arr[0]);
    q.push(root);
    int i=1,j=2;
    while(q.size()>0 && i<n){
        node* temp=q.front();
        q.pop();
        node* l;
        node* r;
        if(arr[i]!=INT_MIN) l=new node(arr[i]);
        else l=NULL;
        if(j<n && arr[j]!=INT_MIN) r=new node(arr[j]);
        else r=NULL;
        temp->left=l;
        temp->right=r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        i+=2;
        j+=2;
    }
return root;
}
int levels(node* root){
    if(root==NULL) return 0;
    return 1+ max(levels(root->left),levels(root->right));
}
void nthlevel(node* root,int curr,int target){
    if(root==NULL) return ;
    if(curr==target) {
        cout<<root->val<<" ";
        return;
    }
    nthlevel(root->left,curr+1,target);
    nthlevel(root->right,curr+1,target);
}
void levelorder(node* root){
    int n=levels(root);
    for(int i=1;i<=n;i++){
        nthlevel(root,1,i);
        cout<<endl;
    }
}
int main(){
    int arr[]={1,2,3,4,5,INT_MIN,6,7,INT_MIN,8,INT_MIN,9,10,11,INT_MIN,12,INT_MIN,13,INT_MIN,14,15,16,INT_MIN,17,18,19,INT_MIN,INT_MIN,20,21,22,23,INT_MIN,24,25,26,29,INT_MIN,INT_MIN,28};
    int n=sizeof(arr)/sizeof(arr[0]);
    node* root=construct(arr,n);
    // boundary traversal
    //boundary(root);
    levelorder(root);
}