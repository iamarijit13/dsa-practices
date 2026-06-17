class MyHashMap {
private:
    struct ListNode {
        int key, val;
        ListNode* next;
        ListNode(int k = -1, int v = -1, ListNode* n = nullptr) : key(k), val(v), next(n) {};
    };
    vector<ListNode*> map;
    int hash(int k) {
        return k % map.size();
    }
public:
    MyHashMap() {
        map.resize(10000);
        for (auto& bucket : map) {
            bucket = new ListNode(0);
        }
    }
    
    void put(int key, int value) {
        ListNode* cur = map[hash(key)];
        while (cur -> next) {
            if (cur -> next -> key == key) {
                cur -> next -> val = value;
                return;
            }
            cur = cur -> next;
        }
        cur -> next = new ListNode(key, value);
    }
    
    int get(int key) {
        ListNode* cur = map[hash(key)] -> next;
        while (cur) {
            if (cur -> key == key) {
                return cur -> val;
            }
            cur = cur -> next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* cur = map[hash(key)];
        while (cur -> next) {
            if (cur -> next -> key == key) {
                ListNode* temp = cur -> next;
                cur -> next = temp -> next;
                delete temp;
                return;
            }
            cur = cur -> next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */