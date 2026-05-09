class MyHashSet {
    vector<list<int>> data;
    static const int SIZE = 1000;

public:
    MyHashSet() {
        data.resize(SIZE);
    }

    void add(int key) {
        int index = key % SIZE;

        for (int num : data[index]) {
            if (num == key) return;
        }

        data[index].push_back(key);
    }

    void remove(int key) {
        int index = key % SIZE;
        data[index].remove(key);
    }

    bool contains(int key) {
        int index = key % SIZE;

        for (int num : data[index]) {
            if (num == key) return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */