class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = INT_MAX;
        int sum = 0;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            sum += nums[right];
            while(sum >= target){
               minLength = min(minLength,right - left + 1);
               sum -= nums[left];
               left++; 
            }
            right++;
        }
        if(minLength == INT_MAX) return 0;
        return minLength;
        
    }
};