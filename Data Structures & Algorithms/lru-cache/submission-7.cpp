// class Node {
// public:
//     int key, val;
//     Node* left, *right;
//     Node(int key, int val) {
//         this -> key = key;
//         this -> val = val;
//         this -> left = right = NULL;
//     }
// };

// class LRUCache {
// private:
// int capacity;
// map<int, Node*> cache;
// Node* left, *right;

// void insert(Node* node) {
//     this -> right -> left -> right = node;
//     node -> left = this -> right -> left;
//     node -> right = this -> right;
//     this -> right -> left = node;
// }

// void remove(Node* node) {
//     node -> left = this -> left;
//     node -> right = this -> left -> right;
//     this -> left -> right -> left = node;
//     this -> left -> right = node;
// }
// public:
//     LRUCache(int capacity) {
//         this -> capacity = capacity;
//         this -> left = new Node(0, 0);
//         this -> right = new Node(0, 0);
//         this -> left -> right = this -> right;
//         this -> right -> left = this -> left;
//     }
    
//     int get(int key) {
//         if (this -> cache.count(key)) {
//             Node* node = this -> cache[key];
//             this -> remove(node);
//             this -> insert(node);
            
//             return node -> val;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         if (this -> cache.count(key)) {
//             this -> remove(this -> cache[key]);
//         }
//         Node* node = new Node(key, value);
//         this -> cache[key] = node;
//         this -> insert(node);
//         if (this -> cache.size() > this -> capacity) {
//             this -> remove(this -> left -> right);
//             this -> cache.erase(this -> left -> right -> key);
//         }
//     }
// };

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
