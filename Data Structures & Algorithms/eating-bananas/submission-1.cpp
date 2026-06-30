class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        auto max_it = max_element(piles.begin(),piles.end());
        int right = *max_it;
        int minK = right;
        while(left <= right){
            int k = (left + right) / 2;
            int hours = eatBanana(k,piles);
            if(hours <= h){
               minK = min(k,minK);
               right = k - 1;
            }
            else left = k + 1;
        }
        return minK;
    }
    int eatBanana(int speed, vector<int>& nums){
        int res = 0;
        for(int num: nums){
            res += num / speed;
            if(num % speed != 0){
                res++; 
            }
        }
        return res;
    }
};
