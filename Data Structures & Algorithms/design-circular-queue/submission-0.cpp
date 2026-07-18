class MyCircularQueue {
    int front;
    int back;
    int sz;
    int cap;
    vector<int> queue;
public:
    MyCircularQueue(int k) {
        queue.resize(k);
        cap = k;
        front = 0;
        back = -1;
        sz = 0;
    }
    
    bool enQueue(int value) {
        if(sz == cap) return false;
        back = back + 1;
        int idx = back % cap;
        queue[idx] = value;
        sz = sz + 1;
        return true;
    }
    
    bool deQueue() {
        if(sz == 0) return false;
        front = (front + 1) % cap;
        sz = sz - 1;
        return true;
    }
    
    int Front() {
        if(sz == 0) return -1;
        return queue[front % cap];
    }
    
    int Rear() {
        if(sz == 0) return -1;
        return queue[back % cap];
    }
    
    bool isEmpty() {
        if(sz == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(sz == cap) return true;
        return false;
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