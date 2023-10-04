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
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next ||!k) return head;

        ListNode* last=head;
        int count=1;

        while(last->next)
        {
            last=last->next;
            count++;
        }
        k=k%count;
        if(k==0)return head;
        count-=k;

        ListNode* temp=head;

        while(--count)
        {
            temp=temp->next;
        }

        last->next=head;
        head=temp->next;
        temp->next=NULL;

        
        return head;
        
    }
};