class DynamicArray {
    int* arr_;
    int capacity_;
    int size_;

public:

    DynamicArray(int capacity) {
        arr_ = new int[capacity_];
        capacity_ = capacity;
        size_ = 0;
    }

    int get(int i) {
        return arr_[i];
    }

    void set(int i, int n) {
        arr_[i] = n;
    }

    void pushback(int n) {
        if (size_ == capacity_) { resize(); };
        arr_[size_] = n;
        ++size_;
    }

    int popback() {
        return arr_[--size_];
    }

    void resize() {
        int* old = arr_;
        arr_ = new int[capacity_*2];
        for (int i = 0; i < size_; ++i) {
            arr_[i] = old[i];
        }
        delete[] old;
        capacity_*=2;
    }

    int getSize() {
        return size_;
    }

    int getCapacity() {
        return capacity_;
    }
};
