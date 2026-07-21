class DynamicArray {
public:
    int *arr;
    int capacity;
    int size;

    DynamicArray(int capacity) {
        this -> capacity = capacity;
        this -> arr = new int[this -> capacity];
        this -> size = 0;
    }

    ~DynamicArray() {
        delete[] arr;
    }

    int get(int i) {
        if (i >= 0 && this -> size > i) {
            return arr[i];
        }
        return -1;
    }

    void set(int i, int n) {
        if (i >= 0 && i < this -> size) {
            this -> arr[i] = n;
            // this -> size = this -> arr.size();
        }
    }

    void pushback(int n) {
        if (this -> size == this -> capacity) {
            this -> resize();
        }
        this -> arr[this -> size] = n;
        this -> size++;
    }

    int popback() {
        if (this -> size > 0) {
            int re = this -> arr[this -> size - 1];
            arr[this -> size - 1] = 0;
            this -> size = this -> size - 1;
            return re;
        }
        return -1;
    }

    void resize() {
        this -> capacity = this -> capacity * 2;
        int *newarr = new int[this -> capacity];
        for (int i = 0; i < this -> size; i++) {
            newarr[i] = this -> arr[i];
        }
        delete[] this->arr;
        this -> arr = newarr;
        // this -> size = this -> arr.size();
    }

    int getSize() {
        return this -> size;
    }

    int getCapacity() {
        return this -> capacity;
    }
};
