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
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* groupPrev = &dummy;
    ListNode* oldHead = head;
        while(true){
            ListNode* node1 = isAllowed(groupPrev,k);
            if(!node1) break;
            ListNode* futureHead = node1->next;
            ListNode* newHead = reverseList(oldHead,k);
            groupPrev->next = newHead;
            groupPrev = oldHead;
            oldHead->next = futureHead;
            oldHead = futureHead;
        }
        return dummy.next;
    }
    ListNode* isAllowed(ListNode* node,int k){
        while(node && k > 0){
            node = node->next;
            k--;
        }
        return node;
    }
    ListNode* reverseList(ListNode* node, int k){
        ListNode* prev = nullptr;
        for(int i = 0; i < k; i++){
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }
};
