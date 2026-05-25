class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n=strs.length;
        HashMap<String , List<String>>map=new HashMap<>();
        for(String s:strs){
            char[]arr=s.toCharArray();
            java.util.Arrays.sort(arr);
            String key = new String(arr);

            if(!map.containsKey(key)){
               map.put(key, new java.util.ArrayList<>());
            }
            map.get(key).add(s);
        }
        
        java.util.List<java.util.List<String>> list = new java.util.ArrayList<>();
        for (java.util.List<String> st : map.values()) {
            list.add(st);
        }
        return list;
    }
}