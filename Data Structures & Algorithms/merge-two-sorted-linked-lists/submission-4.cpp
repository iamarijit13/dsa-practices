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
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1 -> val <= list2 -> val) {
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        } else {
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }
    }

    ListNode* mergeTwoListss(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* te = head;
        merge(list1, list2, te);
        return head -> next;
    }

    void merge(ListNode* list1, ListNode* list2, ListNode* merged) {
        if (!list1 && !list2) return;

        if (list1 && list2) {
            if (list1 -> val <= list2 -> val) {
                merged -> next = new ListNode(list1 -> val);
                merge(list1 -> next, list2, merged -> next);
                return;
            } else {
                merged -> next = new ListNode(list2 -> val);
                merge(list1, list2 -> next, merged -> next);
                return;
            }
        }

        if (list1) {
            merged -> next = new ListNode(list1 -> val);
            merge(list1 -> next, list2, merged -> next);
            return;
        }

        if (list2) {
            merged -> next = new ListNode(list2 -> val);
            merge(list1, list2 -> next, merged -> next);
            return;
        }
    }
};
