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
    bool isPalindrome(ListNode* head) {
       ListNode *high = head;
       string s = "";
       while(high != nullptr){
        int v = high->val;
        s += to_string(v);
        high = high->next;
       }
       int l = 0, h = (int)s.length()-1;
       while(l <= h){
        if(s[l] != s[h]){
            return false;
        }
        l++, h--;
       }
       return true;
    }
};