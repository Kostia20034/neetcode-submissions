class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int right = accumulate(weights.begin(),weights.end(),0);
        int left = *max_element(weights.begin(), weights.end());
        int minW = right;
        while(left <= right){
            int w = (right + left) / 2;
            int d = countDays(weights,w);
            if(d <= days){
               minW = min(minW,w);
                right = w - 1;
            }
            else left = w + 1;
        }
        return minW;
    }
    int countDays(vector<int>& weights, int weight){
        int days = 1;
        int sum = 0;
        for(int n: weights){
            if(sum + n <= weight){
                sum += n;
            }
            else{
                days++;
                sum = n;
            }
        }
        return days;
    }
};