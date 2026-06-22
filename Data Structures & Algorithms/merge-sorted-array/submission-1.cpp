class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int l = 0;
    int r = 0;
    int j = m;
    while(r < n && l < m + r){
        if(nums1[l] >= nums2[r]){
            int k = j;
            while(k > l){
                swap(nums1[k],nums1[k-1]);
                k--;
            }
            j++;
            nums1[l] = nums2[r];
            r++; 
        }
        l++;
    }
    while(r < n){
        nums1[j] = nums2[r];
        j++;
        r++;
    }    
    }

};