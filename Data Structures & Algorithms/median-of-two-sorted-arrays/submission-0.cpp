class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2,nums1);

        int left = 0;
        int right = n;
        int sz = (n+m+1) / 2;
        while(left <= right){
            int mid = (left + right) / 2;
            int idx = sz - mid;
            int leftA = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int rightA = (mid == n) ? INT_MAX : nums1[mid];
            int leftB  = (idx == 0) ? INT_MIN : nums2[idx - 1];
            int rightB = (idx == m) ? INT_MAX : nums2[idx];

            if (leftA > rightB) {
                right = mid - 1;
            } 
            else if (leftB > rightA) {
                left = mid + 1;
            }
            else{
                if ((n + m) % 2 != 0) {
                return max(leftA, leftB);
                }
                else {
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                }
            }

        }
        return 0.0;        
    }
};
