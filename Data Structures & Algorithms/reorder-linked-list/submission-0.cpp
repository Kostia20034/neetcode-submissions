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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(head2 != nullptr){
            ListNode *temp = head2->next;
            head2->next = prev;
            prev = head2;
            head2 = temp;
        }
        while(prev != nullptr){
            ListNode* temp = head->next;
            head->next = prev;
            head = prev;
            prev = temp;
        }
    }
};
