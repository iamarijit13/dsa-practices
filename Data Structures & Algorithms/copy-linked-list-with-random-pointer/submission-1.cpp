/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash;
        Node* te = head;

        while (te) {
            hash[te] = new Node(te -> val);
            te = te -> next;
        }

        te = head;
        // Node dummy(0);
        // Node *tx = &dummy;

        while (te) {
            Node* tx = hash[te];
            tx -> next = hash[te -> next];
            tx -> random = hash[te -> random];
            te = te -> next;
            tx = tx -> next;
        }

        return hash[head];
    }
};
