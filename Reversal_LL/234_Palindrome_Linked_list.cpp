// Both slow and fast pointer and reversal linked list

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow; 
        while(curr!=nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr = prev;
        while(curr!=nullptr){
            if(curr->val!=head->val){
                return false;
            }
            else{
                curr = curr->next;
                head = head->next;
            }
        }
        return true;
        
    }
};









class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        int count=0;
        ListNode* temp = head;
        while(temp!=nullptr){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        for(int i=0;i<ans.size()/2;i++){
            if(arr[i]!=arr[ans.size()-i-1)]){
                return false;
            }
        }
        return true;
        
    }
};
