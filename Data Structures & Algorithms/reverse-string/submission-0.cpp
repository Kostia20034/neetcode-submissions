class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            swap(left,right,s);
            left++;
            right--;
        }
    }
    void swap(int l, int r, vector<char>& s){
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
    }
};