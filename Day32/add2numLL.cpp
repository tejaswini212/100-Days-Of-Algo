/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* l3=dummy;
        int carry = 0;
        while(l1!=NULL || l2!=NULL){
            int l1_val = (l1!=NULL)?l1->val:0;
            int l2_val = (l2!=NULL)?l2->val:0;
            int num = l1_val+l2_val+carry;
            carry = num/10;
            ListNode* newNode = new ListNode(num%10);
            l3->next = newNode;
            
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
            l3 = l3->next;
        }
        if(carry>0){
            ListNode* newNode = new ListNode(carry);
            l3->next = newNode;
            l3 = l3->next;
        }
        return dummy->next;
    }
};