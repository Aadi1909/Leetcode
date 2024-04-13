class Solution {
public:
    ListNode *start;
    bool check(ListNode *head){
        if(head != nullptr){
            if(!check(head->next)) return 0;
            if(head->val != start->val) return 0;
            start = start->next;
        }
        return 1;
    }
    bool isPalindrome(ListNode* head) {
        start = head;
        return check(head);
    }
};