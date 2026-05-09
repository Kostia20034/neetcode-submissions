class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxCount = 0;
        int maxValue = 0;
        for(int num : nums){
            map[num]++;
            if(map[num] > maxCount){
                maxValue = num;
                maxCount = map[num];
            }
        }
        return maxValue;
    }
};