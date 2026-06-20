class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int currentPrefix = 0;
        int count = 0;
        for(int num : nums){
            currentPrefix+=num;
            if(map.contains(currentPrefix - k)){
                count += map[currentPrefix-k];
            }
            if(currentPrefix == k){
                count++;
            }
            map[currentPrefix]++;
        }
        return count;
    }
};