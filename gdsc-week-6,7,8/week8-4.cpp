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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next== NULL)
            return head;
        head->next= deleteDuplicates(head->next);
        return head->val==head->next->val ? head->next:head;
        
        
    
        
       /*  if(head==NULL)
            return NULL;
         ListNode *p,*t;
        p=head;
        t=head->next;
        while(p)
        {
        
            if(t->val==p->val)
            {
                t->next=p->next;
            
                p=t->next;
            }
            else
            {
                 t=p;
            p=p->next;
            }
        }
        return head; */
    }
};