class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(),1);
        pre[0] = nums[0];
        for(int i = 1; i < pre.size(); i++){
            pre[i] = nums[i] * pre[i-1];
        }

        vector<int> post(nums.size(),1);
        post[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2; i >= 0; i--){
            post[i] = nums[i] * post[i+1];
        }

        vector<int> result(nums.size(),1);
        result[0] = post[1];
        result[nums.size() - 1] = pre[nums.size()-2];
        for(int i = 1; i < nums.size() - 1; i++){
            result[i] = pre[i-1] * post[i+1];
        }
        return result;
    }
};
