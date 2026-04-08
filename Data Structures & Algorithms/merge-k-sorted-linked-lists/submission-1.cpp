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
            return NULL;
        }
        vector<ListNode*> mergedList = lists;

        while (mergedList.size() > 1) {
            vector<ListNode*> updatedMergedList;
            for (int i = 0; i < mergedList.size(); i += 2) {
                ListNode* l1 = mergedList[i];
                ListNode* l2 = i + 1 < mergedList.size() ? mergedList[i + 1] : NULL;
                updatedMergedList.push_back(mergeTwoSortedList(l1, l2));
            }
            mergedList = updatedMergedList;
        }
        return mergedList[0];
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
