#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
class node{
    public:
    int val;
    node *left;
    node*right;
    node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void display(node *root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
// finding the sum of tree
    int sum(node *root){
        if(root==NULL) return 0;
        int ans= root->val+sum(root->left)+sum(root->right);
        return ans;
    }

// find size of binary tree
    int size(node *root){
        if(root==NULL) return 0;
        return 1+size(root->left)+size(root->right);
    }
// node with maximum value
int maximum(node *root){
    if(root==NULL) return INT_MIN;
    int lmax= maximum(root->left);
    int rmax= maximum(root->right);
    return max(root->val,max(lmax,rmax));

}

int minimum(node *root){
    if(root==NULL) return INT_MAX;
    int lmin=minimum(root->left);
    int rmin=minimum(root->right);
    return min(root->val,min(lmin,rmin));    
}

// find no of levels in binary tree
    int levels(node *root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    // height=level-1
    // size = no of nodes present in binary tree

int main(){

    node *a=new node(1);
    node *b=new node(2);
    node *c=new node(3);
    node *d=new node(4);
    node *e=new node(5);
    node *f=new node(6);
    node *g=new node(7);
    a->left=b; a->right=c;
    b->left=d; b->right=e;
    c->left=f; c->right=g;
   // display(a);
   /*int k=sum(a);
   cout<<k;*/
   /*int l=size(a);
   cout<<l;*/
   int x=levels(a);
   cout<<x;

}