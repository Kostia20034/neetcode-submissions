class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";

        vector<int> t_freq(128,0);
        vector<int>window_freq(128,0);
        int need = 0;
        for(char c : t){
            if(t_freq[c] == 0) need++;
            t_freq[c]++;
        }
        int left = 0;
        int have = 0;
        int minLen = INT_MAX;
        int strInd;

        for(int r = 0; r < s.length();r++){
            char c = s[r];
            window_freq[c]++;
            if(t_freq[c] > 0 && t_freq[c] == window_freq[c]) have++;
            while(need == have){
                if(r - left + 1 < minLen){
                    minLen = min(r - left + 1, minLen);
                    strInd = left;
                }
               
                char x = s[left];
                window_freq[x]--;
                if(t_freq[x] > 0 && window_freq[x] < t_freq[x]) have--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(strInd,minLen);
        
    }
};
