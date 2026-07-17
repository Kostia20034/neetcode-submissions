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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node handles the absolute worst edge case: when left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // 1. Walk up to the node right BEFORE the reversal zone
        ListNode* prevBeforeSublist = dummy;
        for (int i = 1; i < left; ++i) {
            prevBeforeSublist = prevBeforeSublist->next;
        }
        
        // 2. Reversal zone setup
        ListNode* sublistHead = prevBeforeSublist->next;
        ListNode* curr = sublistHead;
        ListNode* prev = nullptr;
        
        // Reverse only the nodes within [left, right]
        for (int i = 0; i <= (right - left); ++i) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // 3. Stitch it all back together using your exact logic!
        // prevNow points to the new head of the reversed portion
        // curr points to the node right after the reversed portion (right->next)
        prevBeforeSublist->next = prev;
        sublistHead->next = curr;
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean memory
        return newHead;
    }
};