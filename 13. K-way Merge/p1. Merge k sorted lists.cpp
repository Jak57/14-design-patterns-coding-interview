// https://leetcode.com/problems/merge-k-sorted-lists/
// https://www.youtube.com/watch?v=kpCesr9VXDA&t=1034s&ab_channel=Techdose

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
class cmp {
    public:
    bool operator() (ListNode* a, ListNode* b) {
        return (a->val > b->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i, j, n;
        n = lists.size();
        ListNode* tmp = NULL;
        priority_queue< ListNode*, vector<ListNode*>, cmp > pq;
        
        for (i = 0; i < n; i++) {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }
        
        if (pq.size() == 0)
            return NULL;
        
        ListNode* head = new ListNode(-1);
        ListNode* prev = head;
        while (!pq.empty()) {
            ListNode* cur = pq.top();
            prev->next = cur;
            prev = cur;
            pq.pop();
            
            if (cur->next != NULL)
                pq.push(cur->next);
        }
        
        return head->next;
    }
};

