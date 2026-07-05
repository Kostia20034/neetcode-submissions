/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        int peek = 0;
        
        // 1. Find the peak element index
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        peek = left;
        
        // 2. Search in the ascending part (0 to peek)
        int index = binarySearch(target, mountainArr, 0, peek, true);
        if (index != -1) return index;
        
        // 3. Search in the descending part (peek to length - 1)
        return binarySearch(target, mountainArr, peek, mountainArr.length() - 1, false);
    }
    
    int binarySearch(int target, MountainArray &mountainArr, int left, int right, bool isAscending) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);
            
            if (midVal == target) {
                return mid;
            }
            
            if (isAscending) {
                if (target < midVal) right = mid - 1;
                else left = mid + 1;
            } else {
                // For descending order, the logic flips
                if (target > midVal) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};