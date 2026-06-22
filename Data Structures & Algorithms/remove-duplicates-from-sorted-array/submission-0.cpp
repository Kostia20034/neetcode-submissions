class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insert = 1;
        int current = 1;
        while(current < nums.size()){
            if(nums[current] != nums[insert - 1]){
                nums[insert] = nums[current];
                insert++;
            }
            current++;
        }
        return insert;
    }
};