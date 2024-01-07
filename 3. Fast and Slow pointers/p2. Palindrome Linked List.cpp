// https://leetcode.com/problems/palindrome-linked-list/

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
        if (head->next == NULL) 
            return true;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = slow->next;
        ListNode* prev = NULL;
        while (slow != NULL) {
            ListNode* tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        
        while (prev != NULL) {
            if (head->val != prev->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        
        return true;
    }
};
