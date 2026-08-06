struct Node {
    int val;
    Node* next, *prev;
    Node(int v, Node* p, Node* n): val(v), next(n), prev(p) {};
};

class MyCircularQueue {
    Node *left, *right;
    int capacity;
    int size;
public:
    MyCircularQueue(int k) {
        this -> capacity = k;
        this -> size = 0;
        this -> left = new Node(0, nullptr, nullptr);
        this -> right = new Node(0, this -> left, nullptr);
        this -> left -> next = this -> right;
    }
    
    bool enQueue(int value) {
        if (this -> isFull()) return false;
        Node* node = new Node(value, this -> right -> prev, this -> right);
        this -> right -> prev -> next = node;
        this -> right -> prev = node;
        size += 1;
        return true;
    }
    
    bool deQueue() {
        if (this -> isEmpty()) return false;
        Node* node = this -> left -> next;
        this -> left -> next = this -> left -> next -> next;
        this -> left -> next -> prev = left;
        this -> size -= 1;
        delete node;
        return true;
    }
    
    int Front() {
        if (this -> isEmpty()) return -1;
        return this -> left -> next -> val;
    }
    
    int Rear() {
        if (this -> isEmpty()) return -1;
        return this -> right -> prev -> val;
    }
    
    bool isEmpty() {
        return this -> size == 0;
    }
    
    bool isFull() {
        return this -> size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */