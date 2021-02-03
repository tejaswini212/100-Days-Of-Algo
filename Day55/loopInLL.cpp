#include<iostream>
#include<cmath>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int data){
        this->data = data;
        next = NULL;
    }
};

ListNode* findBegLL(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            break;
    }
    if(fast==NULL || fast->next==NULL)
        return NULL;
    slow=head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

int main(){
    ListNode* head1 = new ListNode(7);
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(6);
    head1->next->next->next = new ListNode(3);
    head1->next->next->next->next = new ListNode(10);
    head1->next->next->next->next->next = new ListNode(8);
    head1->next->next->next->next->next->next = new ListNode(2);
    head1->next->next->next->next->next->next->next = head1->next->next->next->next;

    ListNode* intersection = findBegLL(head1);

    cout<<intersection<<" "<<intersection->data;
    return 0;
}
