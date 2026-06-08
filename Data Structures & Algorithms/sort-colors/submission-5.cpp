class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < nums.size() && nums[i] == 0){
            i++;
        }
        while(j >= 0 && nums[j] == 2){
            j--;
        }
        int k = i;
        while(k <= j){
            if(nums[k] == 0){
                swap(nums,k,i);
                i++;
                if(nums[k] == 0){
                    k++;
                }
            }
            else if(nums[k] == 2){
                swap(nums,k,j);
                j--;
            }
            else{
                k++;
            }
        }
    }

    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};