class LRUCache {
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v): key(k), val(v), next(nullptr), prev(nullptr) {};
    };

    unordered_map<int, Node*> hash;
    Node* head;
    Node* tail;
    int capacity;
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        this -> head = new Node(0, 0);
        this -> tail = new Node(0, 0);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if (hash.count(key)) {
            Node* node = hash[key];
            remove(node);
            insert(node);
            return node -> val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (this -> hash.count(key)) {
            Node* node = hash[key];
            node -> val = value;
            remove(node);
            insert(node);
        } else if (this -> capacity == hash.size()) {
            Node* node = tail -> prev;
            remove(node);
            hash.erase(node -> key);
            delete(node);
            node = new Node(key, value);
            insert(node);
            hash[key] = node;
        } else {
            Node* node = new Node(key, value);
            insert(node);
            hash[key] = node;
        }
    }

private:
    void insert(Node* node) {
        node -> next = head -> next;
        node -> prev = head;
        head -> next = node;
        node -> next -> prev = node;

    }

    void remove(Node* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
};
