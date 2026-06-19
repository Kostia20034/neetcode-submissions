class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>sets(nums.begin(), nums.end());
        int length = 0;
        for(int n : sets){
            if(!sets.count(n-1)){
                int count = 1;
                int current = n;
                while(sets.count(current + 1)){
                    count++;
                    current++;
                }
                if(count > length){
                    length = count;
                }
            }
        }
        return length;
    }
};
