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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* list1 = lists[i];
                ListNode* list2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeTwoSortedList(list1, list2));
            }
            lists = mergedLists;
        }

        return lists[0];
    }

    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* re = &dummy;

        while (l1 && l2) {
            if (l1 -> val <= l2 -> val) {
                re -> next = l1;
                l1 = l1 -> next;
            } else {
                re -> next = l2;
                l2 = l2 -> next;
            }
            re = re -> next;
        }

        if (l1) {
            re -> next = l1;
        }

        if (l2) {
            re -> next = l2;
        }

        return dummy.next;
    }
};
