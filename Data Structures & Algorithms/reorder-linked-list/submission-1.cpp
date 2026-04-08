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
        ListNode *slow, *fast;
        slow = head;
        fast = slow -> next;

        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode *head1 = head, *head2 = slow -> next;
        slow -> next = nullptr;


        head2 = reverseList(head2);

        while (head2) {
            ListNode* t = head1 -> next;
            head1 -> next = head2;
            ListNode* t2 = head2 -> next;
            head2 -> next = t;
            head2 = t2;
            head1 = t;
        }

        // while (head2) {
        //     cout << head2 -> val << " ";
        //     head2 = head2 -> next;
        // }
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head -> next -> next = head;
        head -> next = nullptr;

        return newHead;
    }
};
