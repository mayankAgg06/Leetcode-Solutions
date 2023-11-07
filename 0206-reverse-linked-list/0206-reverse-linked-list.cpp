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
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next)return head;
        
        ListNode* p=NULL;
        ListNode* c=head;
        ListNode* n=c->next;
        
        ListNode* tail=head;
        
        while(tail->next)tail=tail->next;
        
        while(c)
        {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        swap(head,tail);
        
        return head;
        
    }
};