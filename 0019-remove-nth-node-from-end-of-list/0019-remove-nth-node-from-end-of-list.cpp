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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(!head || !head->next)return NULL;


        ListNode* front=head;
        ListNode* back=head;

        while(n--)
        {
            front=front->next;
        }
        if(!front)return head->next;

        while(front->next)
        {
            back=back->next;
            front=front->next;
        }

        back->next=back->next->next;

        return head;
        
    }
};