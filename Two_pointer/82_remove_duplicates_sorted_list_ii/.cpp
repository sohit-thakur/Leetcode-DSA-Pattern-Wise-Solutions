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
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!=nullptr&&curr->next!=nullptr){
            if(curr->val==curr->next->val){
                int dup = curr->val;
                while(curr&&curr->val==dup){
                    curr = curr->next;
                }
                if(prev){
                prev->next = curr;
                }
                else{
                    head = curr;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
        
    }
};