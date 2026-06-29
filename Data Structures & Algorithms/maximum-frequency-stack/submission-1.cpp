class FreqStack {
    int maxFreq;
    unordered_map<int, int> mp;
    vector<vector<int>> vec;

public:
    FreqStack() {
        maxFreq = 0;
        // Pre-allocate slots from index 0 to 9 safely
        vec.resize(10); 
    }
    
    void push(int val) {
        mp[val]++;
        int freq = mp[val];
        
        if (freq > maxFreq) {
            maxFreq = freq;
        }
        
        // If an element's frequency hits 10 or higher, 
        // dynamically expand it just like before!
        if (freq >= vec.size()) {
            vec.resize(freq + 1);
        }
        
        vec[freq].push_back(val);
    }

    int pop() {
        int res = vec[maxFreq].back();
        vec[maxFreq].pop_back();
        
        // Update frequency in our map
        mp[res]--;
        
        // If this frequency level is now empty, step down
        if (vec[maxFreq].empty()) {
            maxFreq--;
        }
        
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */