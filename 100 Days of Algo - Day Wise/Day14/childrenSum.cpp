#include<bits/stdc++.h>
using namespace std;
int maxLevel=0;

class node{
    public:
        int val;
        node* left;
        node* right;
    node(int val){
        this->val=val;
        left=right=NULL;
    }
};

bool childSum(node* root){
    if(root==NULL) return true;
    if(root->left==NULL && root->right==NULL) return true;
    int sum=0;
    if(root->left!=NULL) sum+=root->left->val;
    if(root->right!=NULL) sum+=root->right->val;
    return(sum==root->val && childSum(root->left) && childSum(root->right));
}

int main(){
    node* root=new node(42);
    root->left=new node(15);
    root->right=new node(27);
    root->left->right=new node(15);
    root->right->left=new node(27);
    if(childSum(root)==true)
        cout<<"Tree follows children sum property\n";
    else
        cout<<"Tree does not follow children sum property\n";
    return 0;
}
