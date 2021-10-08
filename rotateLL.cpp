 ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* curr=head , *fast=head,*slow=head;
        int cnt=0;
        while(curr)
            cnt++,curr=curr->next;
        k=k%cnt;
        if(k==0) return head;
        while(k--)
            fast=fast->next;
        while(fast->next)
            slow=slow->next,fast=fast->next;
        
        ListNode* temp = slow->next;
        slow->next=NULL;
        fast->next=head;
            
            return temp;
    }