#include<iostream>
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

class PartialSum{
public:
    ListNode* sum = NULL;
    int carry;
    PartialSum(){
        carry = 0;
    }
};

int lengthOfLL(ListNode* head){
    if(head==NULL)
        return 0;
    return lengthOfLL(head->next)+1;
}

ListNode* insertBefore(ListNode* l,int data){
    ListNode* node = new ListNode(data);
    if(l!=NULL)
        node->next = l;
    return node;
}

ListNode* padList(ListNode* l, int padding){
    ListNode* head = l;
    for(int i=0;i<padding;i++)
        head = insertBefore(head,0);
    return head;
}

PartialSum* addUtil(ListNode* l1,ListNode* l2){
    if(l1==NULL && l2==NULL){
        PartialSum* sum = new PartialSum();
        return sum;
    }
    PartialSum* sum = addUtil(l1->next,l2->next);
    int val = sum->carry + l1->data + l2->data;

    ListNode* full_res = insertBefore(sum->sum,val%10);
    sum->sum = full_res;
    sum->carry = val/10;
    return sum;
}

ListNode* addLists(ListNode* l1,ListNode* l2,int carry){
    int len1 = lengthOfLL(l1);
    int len2 = lengthOfLL(l2);
    if(len1<len2)
        l1 = padList(l1,len2-len1);
    else
        l2 = padList(l2,len1-len2);

    PartialSum* sum=addUtil(l1,l2);
    if(sum->carry==0)
        return sum->sum;
    else{
        ListNode* res = insertBefore(sum->sum,sum->carry);
        return res;
    }
}

int main(){
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(7);
    ListNode* res = addLists(head1, head2, 0);
    while(res){
        cout<<res->data<<" ";
        res=res->next;
    }
    cout<<"\n";
    return 0;
}
