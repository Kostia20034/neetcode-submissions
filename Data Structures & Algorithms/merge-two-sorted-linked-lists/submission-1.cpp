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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dumb = new ListNode(0);
        ListNode* last = dumb;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val >= list2->val){
                last->next = list2;
                list2 = list2->next;
            }
            else{
                last->next = list1;
                list1 = list1->next;
            }
            last = last->next;
        }
        if(list1 != nullptr) last->next = list1;
        if(list2 != nullptr) last->next = list2;

        return dumb->next;
        
    }
};
