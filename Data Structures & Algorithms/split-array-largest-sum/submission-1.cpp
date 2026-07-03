class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        for(int num : nums){
        l = max(l,num);
        r += num;
        }
        while(l < r){
            int m = (l+r) / 2;
            if(canSplit(nums,k,m)){
                r = m;
            }
            else l = m + 1;
        }
        return l;
    }
    bool canSplit(vector<int>& nums, int k, int maxSum){
        int sum = 0;
        int subarrays = 1;
        for(int num : nums){
            if(num + sum > maxSum){
                subarrays++;
                sum = num;
                if(subarrays > k) return false;
            }
            else sum += num;
        }
        return true;
    }
};