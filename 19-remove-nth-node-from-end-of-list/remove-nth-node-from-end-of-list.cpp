class Solution {
public:
    ListNode *rem, *todelete, *start;
    bool ok = false;
    int count = 0;
    void solve(ListNode *head, int n){
        if (head != nullptr) {
            solve(head->next, n);
            count += 1;
            if (count == n) {
                rem = head->next;
                todelete = head;
            }
            if (count == n + 1) {
                ok = true;
                head->next = rem;
                delete todelete;
            }
            if(head == start && ok == false){
                start = head->next;
                delete head;
                return ;
            }
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        start = head;
        if(head->next == nullptr){
            return nullptr;
        }
        solve(head, n);
        return start;
    }
};