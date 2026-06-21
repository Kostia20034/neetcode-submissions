class Solution {
public:
    bool isPal(string s, int left, int right){
        while(left < right){
            while(ispunct(s[left]) || isspace(s[left])){
                left++;
            }
            while(ispunct(s[right]) || isspace(s[right])){
                right--;
            }
            if(tolower(s[right]) != tolower(s[left])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        bool allowed = true;
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            while(ispunct(s[left]) || isspace(s[left])){
                left++;
            }
            while(ispunct(s[right]) || isspace(s[right])){
                right--;
            }
            if(tolower(s[right]) != tolower(s[left])){
                return isPal(s,left+1,right) || isPal(s,left,right-1);
            }
            left++;
            right--;
        }
        return true;
    }
};