class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int n: asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top() > 0 &&  n < 0){
                if(abs(st.top()) > abs(n)){
                    destroyed = true;
                    break;
                }
                else if(abs(st.top()) < abs(n)){
                    st.pop();
                }
                else{
                    st.pop();
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) st.push(n);
    }
    vector<int> res(st.size());
    for(int i = res.size() - 1; i >= 0; i--){
        res[i] = st.top();
        st.pop();
    }
    return res;
    }
};