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

void deleteMid(ListNode* node){
    if(node==NULL || node->next==NULL)
        return;
    ListNode* n=node->next;
    node->data = n->data;
    node->next = n->next;
    return;
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

    deleteMid(head->next->next);

    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
    return 0;
}
