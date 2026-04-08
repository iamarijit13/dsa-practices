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
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
        vector<ListNode*> l1s;
        vector<ListNode*> l2s;

        while (l1) {
            l1s.push_back(l1);
            l1 = l1 -> next;
        }

        while (l2) {
            l2s.push_back(l2);
            l2 = l2 -> next;
        }

        ListNode dummy(0);
        ListNode* te = &dummy;
        int i = l1s.size() - 1, j = l2s.size() - 1;
        while (i >= 0 && j >= 0) {
            int re = l1s[i] -> val + l2s[j] -> val;

            while (re > 10) {
                te -> next = new ListNode(re / 10);
                re %= 10;
                te = te -> next;
            }

            if (re != 0) {
                te -> next = new ListNode(re);
                te = te -> next;
            }
            i--;
            j--;
        }

        while (i >= 0) {
            te -> next = new ListNode(l1s[i] -> val);
            te = te -> next;
            i--;
        }
        while (j >= 0) {
            te -> next = new ListNode(l1s[j] -> val);
            te = te -> next;
            j--;
        }

        te = dummy.next;
        while (te) {
            cout << te -> val << " ";
            te = te -> next;
        }
        return reverseList(dummy.next);
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }

        ListNode* cur = reverseList(head -> next);

        head -> next -> next = head;
        head -> next = NULL;

        return cur;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* te = &dummy;
        int c = 0;
        while (l1 && l2) {
            int re = l1 -> val + l2 -> val + c;

            if (re >= 10) {
                te -> next = new ListNode(re % 10);
                c = re / 10;
                te = te -> next;
            } else {
                te -> next = new ListNode(re);
                te = te -> next;
                c = 0;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }

        while (l1) {
            int re = l1 -> val + c;
            if (re >= 10) {
                te -> next = new ListNode(re % 10);
                c = re / 10;
                te = te -> next;
            } else {
                te -> next = new ListNode(re);
                te = te -> next;
                c = 0;
            }
            l1 = l1 -> next;
        }
        if (l2) {
            int re = l2 -> val + c;
            if (re >= 10) {
                te -> next = new ListNode(re % 10);
                c = re / 10;
                te = te -> next;
            } else {
                te -> next = new ListNode(re);
                te = te -> next;
                c = 0;
            }
            l2 = l2 -> next;
        }
        if (c) {
            te -> next = new ListNode(c);
        }
        return dummy.next;
    }
};
