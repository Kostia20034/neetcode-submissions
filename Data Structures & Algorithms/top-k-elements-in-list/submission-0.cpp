class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,Compare> pq;
        for(pair<int,int> pr : map){
            pq.push(pr);
        }

        while(k > 0){
            result.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return result;
        
    }
    struct Compare{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        }
    };
};
