class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int m = (l+r) / 2;
            if(nums[m] == target){
                return true;
            }
            if (nums[l] == nums[m] && nums[m] == nums[r]) {
                l++;
                r--;
                continue; 
            }
            else if(nums[m] <= nums[r]){ // right part is sorted
                if(target <= nums[r] && target > nums[m]){
                    l = m + 1;
                }
                else r = m - 1;
            }
            else{//left part is sorted
                if(target >= nums[l] && target < nums[m]){
                    r = m - 1;
                }
                else l = m + 1;
            }
        }
        return false;
    }
};