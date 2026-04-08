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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* te = &dummy;
        int c = 0;
        while (l1 || l2 || c) {
            int v1 = l1 ? l1 -> val : 0;
            int v2 = l2 ? l2 -> val : 0;
            int re = v1 + v2 + c;

            if (re >= 10) {
                te -> next = new ListNode(re % 10);
                c = re / 10;
                te = te -> next;
            } else {
                te -> next = new ListNode(re);
                te = te -> next;
                c = 0;
            }
            l1 = l1 ? l1 -> next : NULL;
            l2 = l2 ? l2 -> next : NULL;
        }

        // while (l1) {
        //     int re = l1 -> val + c;
        //     if (re >= 10) {
        //         te -> next = new ListNode(re % 10);
        //         c = re / 10;
        //         te = te -> next;
        //     } else {
        //         te -> next = new ListNode(re);
        //         te = te -> next;
        //         c = 0;
        //     }
        //     l1 = l1 -> next;
        // }
        // if (l2) {
        //     int re = l2 -> val + c;
        //     if (re >= 10) {
        //         te -> next = new ListNode(re % 10);
        //         c = re / 10;
        //         te = te -> next;
        //     } else {
        //         te -> next = new ListNode(re);
        //         te = te -> next;
        //         c = 0;
        //     }
        //     l2 = l2 -> next;
        // }
        // if (c) {
        //     te -> next = new ListNode(c);
        // }
        return dummy.next;
    }
};
