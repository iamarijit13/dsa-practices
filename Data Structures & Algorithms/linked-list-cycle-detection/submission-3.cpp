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
    bool hasCycles(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) return true;
        }
        return false;
    }

    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visit;

        while (head) {
            if (visit.count(head)) return true;
            visit.insert(head);
            head = head -> next;
        }
        return false;
    }
};
