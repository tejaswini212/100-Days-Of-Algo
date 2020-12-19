#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int val;
    node* left;
    node* right;
};

node* newNode(int val){
    node* Node = new node();
    Node->val = val;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}

bool validPathSum(node* Node,int sum){
    if(Node==NULL)
        return false;
    else{
    int sub = sum - Node->val;
    if(sub==0 && Node->left==NULL && Node->right==NULL)
        return true;
    return validPathSum(Node->left,sub) || validPathSum(Node->right,sub);
    }
}

int main(){

    int sum = 26;
    
    node* root=newNode(5);
    root->left=newNode(4);
    root->right=newNode(8);
    root->left->left=newNode(11);
    root->left->left->left=newNode(7);
    root->left->left->right=newNode(2);
    root->right->left=newNode(13);
    root->right->right=newNode(4);
    root->right->right->right=newNode(1);
    
    if(validPathSum(root,sum))
        cout<<"Path exists\n";
    else
        cout<<"Path doesn't exist\n";
        
    return 0;
}
