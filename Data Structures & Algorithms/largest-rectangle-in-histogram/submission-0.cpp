class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<pair<int,int>> st;
        int maxArea = 0;
        for(int i = 0; i < heights.size();i++){
            int start = i;
            while(!st.empty() && st.top().second > heights[i]){
                int height = st.top().second;
                int orgInd = st.top().first;
                int area = (i - orgInd) * height;
                if(area > maxArea) maxArea = area;
                st.pop();
                start = orgInd;
            }
        st.push({start,heights[i]});
        }
        return maxArea;
    }
};
