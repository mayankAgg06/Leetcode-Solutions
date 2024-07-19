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
    void reorderList(ListNode* head) {
        stack<ListNode*> helper;

        ListNode* curr=head;

        while(curr)
        {
            helper.push(curr);
            curr=curr->next;
        }

        curr = head;
        unordered_map<ListNode*, bool> visited;

        while(true)
        {
             ListNode* last = helper.top();
            helper.pop();
            ListNode* next = curr->next;
            visited[curr] = true;
            if(visited[last]){ 
                curr->next = NULL; 
                break; 
            } 
            curr->next = last; 
            visited[last] = true;
            curr = curr->next; 
            if(visited[next]){
                curr->next = NULL;
                break;
            }
            curr->next = next;
            curr = curr->next;
        }
    
    }
};