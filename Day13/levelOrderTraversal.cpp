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

int height(node* Node){
    if(Node==NULL)
         return 0;
    else{
         int lefth=height(Node->left);
         int righth=height(Node->right);
         if(lefth>righth)
              return lefth+1;
         return righth+1;
    }
}

void printCurrLev(node* Node,int level){
     if(Node==NULL)
         return;
     if(level==1)
         cout<<Node->val<<" ";
     else if(level>1)
     {
         printCurrLev(Node->left,level-1);
         printCurrLev(Node->right,level-1);
     }
}

void printLevelTrav(node* root){
     int h = height(root);
     //cout<<h;
     int i;
     for(i=1;i<=h;i++)
          printCurrLev(root, i);
     cout<<"\n";
}

int main(){

    node* root=newNode(5);
    root->left=newNode(4);
    root->right=newNode(8);
    root->left->left=newNode(11);
    root->left->left->left=newNode(7);
    root->left->left->right=newNode(2);
    root->right->left=newNode(13);
    root->right->right=newNode(4);
    root->right->right->right=newNode(1);
    
    cout<<"Level order traversal:\n";
    printLevelTrav(root);
    
    return 0;
}
