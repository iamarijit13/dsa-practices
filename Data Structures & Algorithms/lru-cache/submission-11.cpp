class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node *prev, *next;

        Node(int k, int v, Node *p, Node *n) : key(k), val(v), prev(p), next(n) {};
        Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {};
    };

    int capacity;
    Node *head, *tail;
    unordered_map<int, Node*> hash;
public:
    LRUCache(int capacity) {
       this -> capacity = capacity;
       head = new Node(0, 0);
       tail = new Node(0, 0, head, NULL);
       head -> next = tail; 
    }
    
    int get(int key) {
        if (this -> hash.count(key)) {
            Node *node = hash[key];
            remove(node);
            insert(node);
            return node -> val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (hash.count(key)) {
            Node *node = hash[key];
            node -> val = value;
            remove(node);
            insert(node);
        } else if (hash.size() == capacity) {
            Node* node = tail -> prev;
            hash.erase(node -> key);
            remove(node);
            delete node;

            Node *current = new Node(key, value);
            insert(current);
            hash[key] = current;
        } else {
            Node *current = new Node(key, value);
            insert(current);
            hash.insert({key, current});
        }
    }
private:
    void insert(Node *node) {
        node -> prev = head;
        node -> next = head -> next;
        head -> next -> prev = node;
        head -> next = node;
    }

    void remove(Node *node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
};
