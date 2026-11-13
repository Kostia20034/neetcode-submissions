class Solution {
    public String longestCommonPrefix(String[] strs) {
    int lowestIndex = findShortestWord(strs);
    String string = strs[lowestIndex];
    for(int i = 0; i < string.length(); i++){
        for(String str : strs){
            if(str.charAt(i) != string.charAt(i)){
                return string.substring(0,i);
            }
        }
    }
    return string;  
    }

    int findShortestWord(String[] strs){
        int min = Integer.MAX_VALUE;
        int lowestIndex = 0;
        for(int i = 0; i < strs.length; i++){
            if(strs[i].length() < min){
                min = strs[i].length();
                lowestIndex = i;
            }
        }
        return lowestIndex;
    }
}