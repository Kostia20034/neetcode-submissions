class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            while(!isalpha(s[left]) && !isdigit(s[left])){
                left++;
            }
            while(!isalpha(s[right]) && !isdigit(s[right])){
                right--;
            }
            if(left < right && tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
