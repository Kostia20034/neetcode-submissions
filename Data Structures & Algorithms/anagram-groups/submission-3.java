class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<List<String>>();
        Map<String,List<String>> map = new HashMap<>();
    for(String s : strs){
        String key = getKey(s);
        if(map.containsKey(key)){
            map.get(key).add(s);
        }
        else map.put(key, new ArrayList<>(List.of(s)));
    }
    for(List<String> list : map.values()){
        result.add(list);
    }
    return result;
        
    }

    String getKey(String s){
        int[] alphabet = new int[26];
        for(int i = 0; i < s.length(); i++){
            alphabet[s.charAt(i) - 'a']++;
        }

        StringBuilder str = new StringBuilder();

        for(int i = 0; i < alphabet.length; i++){
            if(alphabet[i] > 0){
                str.append((char) 'a' + i);
                str.append(alphabet[i]);
            }
        }
        return str.toString();
    }
    
}
