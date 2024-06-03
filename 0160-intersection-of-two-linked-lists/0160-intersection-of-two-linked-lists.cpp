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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            // if(!a)a=headB;
            // if(!b)b=headA;

            // a=a->next;
            // b=b->next;

            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        return a;
    }
};