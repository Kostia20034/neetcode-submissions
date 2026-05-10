class MyHashSet {
    static constexpr int SIZE = 10000; // Better practice to use a constant
    
    struct Node {
        int val;
        Node* next;
        Node(int val, Node* next) : val(val), next(next) {}
    };

    Node* data[SIZE];

public:
    MyHashSet() {
        // Essential: Initialize the array
        for (int i = 0; i < SIZE; i++) data[i] = nullptr;
    }
    
    void add(int key) {
        if (contains(key)) return; // HashSets don't allow duplicates
        int index = key % SIZE;
        // Optimization: Just put the new node at the FRONT of the list
        data[index] = new Node(key, data[index]);
    }
    
    void remove(int key) {
        int index = key % SIZE;
        Node* curr = data[index];
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->val == key) {
                if (prev == nullptr) data[index] = curr->next;
                else prev->next = curr->next;
                delete curr; // Don't forget to free memory!
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    
    bool contains(int key) {
        int index = key % SIZE;
        Node* temp = data[index];
        while (temp != nullptr) {
            if (temp->val == key) return true;
            temp = temp->next;
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