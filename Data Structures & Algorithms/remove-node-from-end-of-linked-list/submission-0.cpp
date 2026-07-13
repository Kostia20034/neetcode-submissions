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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     // Pass 1: Get the total length
    int sz = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        sz++;
        curr = curr->next;
    }
    
    // Edge Case: If we need to remove the head node
    if (sz == n) {
        return head->next; 
    }
    
    // Pass 2: Stop right BEFORE the node to delete
    curr = head;
    for (int i = 0; i < sz - n - 1; i++) {
        curr = curr->next;
    }
    
    // Delete the target node (works for both middle and last nodes!)
    curr->next = curr->next->next;
    
    return head;
}
};
