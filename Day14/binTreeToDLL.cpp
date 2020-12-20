#include<bits/stdc++.h>
using namespace std;

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

void printList(node *head){
    node *curr=head;
    while(curr!=NULL){
        cout<<curr->val<<" ";
        curr=curr->right;
    }cout<<endl;
}

node* BTToDLL(node* root){
    if(root==NULL) return root;
    static node* prev=NULL;
    node* head=BTToDLL(root->left);
    if(prev==NULL) head=root;
    else{
        root->left = prev;
        prev->right = root;
        //cout<<root->val<<" ";
    }
    prev = root;
    BTToDLL(root->right);
    return head;
}

int main(){
    node* root=new node(42);
    root->left=new node(15);
    root->right=new node(27);
    root->left->right=new node(15);
    root->right->left=new node(27);
    cout<<"Convert BT to DLL: ";
    node *head=BTToDLL(root);
    printList(head);
    cout<<"\n";
    
    return 0;
}
