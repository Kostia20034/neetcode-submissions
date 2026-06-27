class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int count = 0;
        vector<pair<int,double>> vec;
        for(int i = 0; i < position.size(); i++){
            vec.push_back({position[i],(double)(target - position[i]) / speed[i]});
        }
        sort(vec.begin(),vec.end());
        stack<pair<int,double>> st;
        for(pair<int,double> pr : vec){
            st.push(pr);
        }

        while(!st.empty()){
            double prev = st.top().second;
            st.pop();
            while(!st.empty() && st.top().second <= prev){
                st.pop();
            }
            count++;
        }
        return count;
    }
};
