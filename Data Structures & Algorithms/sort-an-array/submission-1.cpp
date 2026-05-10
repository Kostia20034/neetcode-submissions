class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(0,nums.size() - 1, nums);
        return nums;
    }
    int partition(int left, int right, vector<int>& nums){
        int pivot = nums[right];
        int i = left;
        for(int j = i; j < right; j++){
            if(nums[j] < pivot){
                swap(i,j,nums);
                i++;
            }
        }
        swap(i,right,nums);
        return i;
    }
    void quickSort(int left, int right, vector<int>& nums){
        if(left >= right) return;
        int pivot = partition(left,right,nums);
        quickSort(left,pivot-1,nums);
        quickSort(pivot+1,right,nums);
    }
    void swap(int l, int r, vector<int>& nums){
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
    }
};