class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] prefix = new int[nums.length];
        int prefixInt = 1;
        for(int i = 0; i < nums.length; i++){
            prefixInt = nums[i] * prefixInt;
            prefix[i] = prefixInt;
        }

        int[] postfix = new int[nums.length];
        int postfixInt = 1;
        for(int i = nums.length-1; i >= 0; i--){
            postfixInt = nums[i] * postfixInt;
            postfix[i] = postfixInt;
        }

        int[] result = new int[nums.length];
        result[0] = postfix[1];
        result[nums.length - 1] = prefix[nums.length - 2];
        for(int i = 1; i < nums.length - 1; i++){
            result[i] = prefix[i-1] * postfix[i+1];
        }
        return result;
    }
}  
