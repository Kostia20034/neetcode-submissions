class MyHashMap {
    struct Node{
        int key;
        int val;
        Node* next;

        Node(int key, int val, Node* next) : key(key), val(val), next(next) {}
    };
    vector<Node*> map;
public:
    MyHashMap() {
        map.resize(10000);
        for(int i = 0; i < 10000; i++){
            map[i] = nullptr;
        }
    }
    
    void put(int key, int value) {
        int index = key % 10000;
        Node* temp = map[index];
        while(temp != nullptr){
            if(temp->key == key){
                temp->val = value;
                return;
            }
        }
        map[index] = new Node(key,value,map[index]);
    }
    
    int get(int key) {
        int index = key % 10000;
        Node* temp = map[index];
        while(temp != nullptr){
            if(temp->key == key){
                return temp->val;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % 10000;
        Node* curr = map[index];
        Node* prev = nullptr;
        while(curr != nullptr){
            if(curr->key == key && prev == nullptr){
                map[index] = curr->next;
                delete curr;
                return;
            }
            if(curr->key == key){
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
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