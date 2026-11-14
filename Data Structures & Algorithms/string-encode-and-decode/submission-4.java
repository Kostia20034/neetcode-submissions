class Solution {

    public String encode(List<String> strs) {
        StringBuilder builder = new StringBuilder("");
        for(String str: strs){
            int length = str.length();
            builder.append(length);
            builder.append('@');
            builder.append(str);
        }
        return builder.toString();
    }

    public List<String> decode(String str) {
        List<String> result = new ArrayList<>();
        if(str.equals("")) return result;
        char[] string = str.toCharArray();
        for(int i = 0; i < str.length(); i++){
            int initial = i;
            while(Character.isDigit(string[i])){
                i++;
            }
            int digit = 0;
            if(i - initial > 0) digit = Integer.parseInt(str.substring(initial,i));
            i++;
            String s = "";
            if(digit != 0) s = str.substring(i,i+digit);
            i += digit - 1;
            result.add(s);
            
        }
        return result;

    }
}
