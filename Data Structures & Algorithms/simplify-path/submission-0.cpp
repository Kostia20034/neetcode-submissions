class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st; // Using vector as a stack
        stringstream ss(path);
        string component;
        
        while (getline(ss, component, '/')) {
            if (component == "" || component == ".") {
                continue;
            }
            if (component == "..") {
                if (!st.empty()) {
                    st.pop_back(); // Works just like pop()
                }
            } else {
                st.push_back(component); // Works just like push()
            }
        }
        
        // Because it's a vector, you CAN loop over it!
        string res = "";
        for (string dir : st) {
            res += "/" + dir;
        }
        
        return res.empty() ? "/" : res;
    }
};