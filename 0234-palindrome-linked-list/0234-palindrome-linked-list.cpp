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
    ListNode* revList(ListNode* head)
    {
        if(!head || !head->next) return head;

        ListNode* p=NULL;
        ListNode* c=head;
        ListNode* n= c->next;

        while(c)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }


    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next) return true;

        ListNode* slow= head;
        ListNode* fast= head;

        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* head2= revList(slow);

        while(head and head2)
        {
            if(head->val==head2->val)
            {
                head=head->next;
                head2=head2->next;
            }
            else return false;
        }

        return true;
    }
};