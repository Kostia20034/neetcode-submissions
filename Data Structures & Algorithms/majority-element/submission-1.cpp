class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        int maxCount = 0;
        int maxValue = 0;
        for(auto [key,value] : map){
            if(value > maxCount){
                maxValue = key;
                maxCount = value;
            }
        }
        return maxValue;
    }
};