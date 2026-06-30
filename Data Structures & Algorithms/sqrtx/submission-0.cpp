class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }

        int left = 1;
        int right = x;
        int res = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2; // Prevents overflow during middle calculation
            long long square = mid * mid;

            if (square == x) {
                return mid; // Perfect square found
            } 
            else if (square < x) {
                res = mid;     // mid could be the answer rounded down, save it
                left = mid + 1; // Look for a larger valid integer
            } 
            else {
                right = mid - 1; // mid is too large, look smaller
            }
        }

        return res;
    }
};