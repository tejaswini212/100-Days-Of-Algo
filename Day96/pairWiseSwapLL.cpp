void pairWiseSwap(struct node *head)
{
   // The task is to complete this method
   struct node *p = head;
   struct node *q = head->next;
   int temp;
   while(p && q)
    {
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        if(!q->next || !q->next->next)
            break;
        else{    
        p = p->next->next;
        q=q->next->next;
        }
    }
}