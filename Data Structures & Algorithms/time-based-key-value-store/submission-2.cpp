class TimeMap {
    unordered_map<string,vector<pair<int,string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!store.contains(key)) return "";
        int l = 0;
        int r = store[key].size() - 1;
        int mid = 0;
        while(l <= r){
            mid = (l+r) / 2;
            if(store[key][mid].first == timestamp){
                return store[key][mid].second;
            }
            else if( timestamp < store[key][mid].first){
                r = mid - 1;
            }
            else l = mid + 1;
        }
        auto zero = store[key][0];
         if( timestamp < zero.first) return "";
        return store[key][r].second;
    }
};
