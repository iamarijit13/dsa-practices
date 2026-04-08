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
    ListNode* reverseKGroups(ListNode* head, int k) {
        int x = k;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* h = &dummy, *t = head;
        while (t) {
            if (!t || x == 0) {
                cout << t -> val;
                ListNode* re = reverseList(h -> next);
                h -> next = re;
                ListNode* e = getEndNode(re);
                // cout << e -> val;
                e -> next = t;
                h = e;
                x = k;
            }
            t = t -> next;
            x--;
        }
        return dummy.next;
    }

    ListNode* getEndNode(ListNode* head) {
        while (head -> next) {
            head = head -> next;
        }
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }

        ListNode* newHead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;

        while (true) {
            // Check if there are k nodes ahead
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;

            // Start reversing
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* curr = groupStart->next;

            for (int i = 1; i < k; i++) {
                groupStart->next = curr->next;
                curr->next = prevGroupEnd->next;
                prevGroupEnd->next = curr;
                curr = groupStart->next;
            }

            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};
