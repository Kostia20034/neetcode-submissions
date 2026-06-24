#include <vector>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        
        for (const string& s : operations) {
            if (s == "+") {
                // Get the top two elements directly from the stack
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                
                // Push them back along with their sum
                st.push(top1);
                st.push(top1 + top2);
            } 
            else if (s == "D") {
                // Double the top element
                st.push(2 * st.top());
            } 
            else if (s == "C") {
                // Invalidate the last score
                st.pop();
            } 
            else {
                // Safe conversion: handles positive, negative, and multi-digit numbers
                st.push(stoi(s));
            }
        }
        
        // Sum up everything remaining in the stack
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};
