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
    bool isPalindrome(ListNode* head) {
      //reversing half linked list
        
        ListNode *fp=head,*sp=head;
        while(fp!=NULL && fp->next!=NULL)
        {
            fp=fp->next->next;  //finding mid using slow and fast pointer
            sp=sp->next;
        }
        ListNode *prev=NULL,*next,*cur=sp;
        while(cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;     //reversing half list
            prev=cur;
            cur=next;
            
        }
        fp=head;
        while(prev!=NULL)
        {
            if(prev->val!=fp->val)
                return false;
            fp=fp->next;             
            prev=prev->next;
        }
        
        return true;
        
        
        
        /*  vector<int>temp,rev;
        while(head)
        {
            temp.push_back(head->val);
            head=head->next;
        }
        rev=temp;
        reverse(rev.begin(),rev.end());
        if(rev==temp)
            return true;
        else 
            return false;   */
    }
};