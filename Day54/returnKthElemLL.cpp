#include<iostream>
#include<set>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int data){
        this->data=data;
        next=NULL;
    }
};

//Simply place one iterator p1 at start and p2 k distance apart
//When p2 reaches the end p1 is at kth position
ListNode* kthElem(ListNode* head,int k){
    ListNode* p1 = head;
    ListNode* p2 = head;
    for(int i=0;i<k;i++){
        if(p1==NULL)
            return NULL;
        p1=p1->next;
    }
    while(p1){
        p1=p1->next;
        p2=p2->next;
    }
    return p2;
}

int main(){
    ListNode* head = new ListNode(2);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(6);
    ListNode* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";

    cout<<kthElem(head, 2)->data;
/*
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
    */
    return 0;
}
