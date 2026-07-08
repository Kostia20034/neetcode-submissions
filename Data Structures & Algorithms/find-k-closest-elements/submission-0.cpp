class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        while(left < right){
            int mid = (left + right) / 2;
            if(abs(arr[mid]-x) < abs(arr[mid+k]-x) || 
            (abs(x - arr[mid]) == abs(x - arr[mid+k]) && arr[mid] < arr[mid+k])){
                right = mid;
            }
            else left = mid + 1;  
        }
        vector<int> result;
        for(int i = left; i < left + k; i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};