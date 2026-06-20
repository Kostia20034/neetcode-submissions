class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]){
                swap(i,nums[i] - 1,nums);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }

    void swap(int i, int j, vector<int>& nums){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};