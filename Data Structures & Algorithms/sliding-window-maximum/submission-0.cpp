class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> deck;
        for(int i = 0; i < nums.size(); i++){
            if(!deck.empty() && deck.front() == i - k) deck.pop_front();

            while(!deck.empty() && nums[deck.back()] < nums[i]) deck.pop_back();
            deck.push_back(i);
            if(i >= k - 1) result.push_back(nums[deck.front()]);

        }
        return result;
    }
};
