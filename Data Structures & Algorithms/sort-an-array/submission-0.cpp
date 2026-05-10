class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return divide(0, nums.size()-1, nums);
    }
    vector<int> divide(int left, int right, vector<int>& nums){
        if(left == right){
            return {nums[left]};
        }
        int mid = left + (right - left) / 2;
        vector<int> first = divide(left, mid, nums);
        vector<int> second = divide(mid+1,right,nums);
        return merge(first,second);
    }

    vector<int> merge(const vector<int> &first, const vector<int> &second){
        int i = 0;
        int j = 0;
        vector<int> result;
        while(i < first.size() && j < second.size()){
            if(first[i] < second[j]){
                result.push_back(first[i]);
                i++;
            }
            else{
               result.push_back(second[j]);
                j++; 
            }
        }
        while(i < first.size()){
            result.push_back(first[i]);
            i++;
        }

        while(j < second.size()){
            result.push_back(second[j]);
            j++;
        }
        return result;
    }
};