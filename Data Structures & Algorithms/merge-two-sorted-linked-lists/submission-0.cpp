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
        ListNode* head = new ListNode(0);
        ListNode* te = head;

        while (list1 && list2) {
            if (list1 -> val > list2 -> val) {
                te -> next = new ListNode(list2 -> val);
                list2 = list2 -> next;
            } else {
                te -> next = new ListNode(list1 -> val);
                list1 = list1 -> next;
            }
            te = te -> next;
        }

        if (list1) {
            te -> next = list1;
        }

        if (list2) {
            te -> next = list2;
        }

        return head -> next;
    }
};
