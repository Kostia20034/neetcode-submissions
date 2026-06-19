class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(string str : strs){
            result += str;
            result += "`";
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string temp = "";
        for(char a : s){
            if(a != '`'){
                temp += a;
            }
            else{
                result.push_back(temp);
                temp = "";
            }
        }
        return result;
    }
};
