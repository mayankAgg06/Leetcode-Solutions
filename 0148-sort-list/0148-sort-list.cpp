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
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp= dummy;

        while(l1 and l2)
        {
            if(l1->val < l2->val) 
            {
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else
            {
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }  

        if(l1)temp->next=l1;
        else temp->next=l2;

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head)
    {
        if(!head || !head->next) return head;

        //finding middle point
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2= slow->next;
        slow->next= NULL;

        //applying merge sort
        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(head2);

        ListNode* sorted= merge(left,right);

        return sorted;

    }
    ListNode* sortList(ListNode* head) {

        return mergeSort(head);
        
    }
};