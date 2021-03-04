/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int lengthOfLL(ListNode* head){
        if(head==NULL)
            return 0;
        int res=0;
        while(head){
            res++;
            head = head->next;
        }
        return res;
    }
        
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = lengthOfLL(headA);
        int sizeB = lengthOfLL(headB);
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        if(sizeA>sizeB){
            int start=sizeA-sizeB;
            while(start--)
                tempA=tempA->next;
        }
        else{
            int start=sizeB-sizeA;
            while(start--)
                tempB=tempB->next;
        }
        while(tempA!=tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};