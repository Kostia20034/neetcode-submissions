class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int l = 0;
        int r = 0;
        while(l < word1.size() && r < word2.size()){
            result += word1[l];
            result += word2[r];
            l++;
            r++;
        }
        if(l < word1.size()) result += word1.substr(l);
        if(r < word2.size()) result += word2.substr(r);
        return result;
    }
};