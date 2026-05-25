class Solution {
    public String encode(List<String> strs) {
        StringBuilder s = new StringBuilder();
        for(String str: strs){
            s.append(str.length());
            s.append('#');
            s.append(str);
        }
        return s.toString();
    }

    public List<String> decode(String s) {
        List<String>result=new ArrayList<>();
        int i=0;
        while(i<s.length()){
            int j=i;

            while(s.charAt(j)!='#')j++;
            int len= Integer.parseInt(s.substring(i,j));
            j++;
            
            String word = s.substring(j, j + len);
            result.add(word);
            i=j+len;
        }
        return result;
    }
}
