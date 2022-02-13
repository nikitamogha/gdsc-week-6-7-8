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
    //sc- const..time 0(n)
    int sizeofnode(ListNode *a)
    {
        int count=0;
        while(a!=NULL)
        {
            count++;
            a=a->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1=sizeofnode(headA);
        int size2=sizeofnode(headB);
        ListNode* a=headA;
        ListNode* b=headB;
        int diff=abs(size1-size2);
        
        if(size1>size2)
        {
            for(int i=0;i<diff;i++)
            {
                a=a->next;
            }
        }
        else
        {
            for(int i=0;i<diff;i++)
            {
                b=b->next;
            }
        }
        while(a!=b)
        {
            a=a->next;
            b=b->next;
        }
        return a;
    }
};