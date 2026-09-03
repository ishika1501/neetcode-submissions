class Solution {
    public boolean isPalindrome(String s) {
        int n = s.length();

        String r = "";
        for (int k = 0; k < n; k++) {
            char ch = s.charAt(k);
            if (Character.isLetterOrDigit(ch)) {
                r += Character.toLowerCase(ch);
            }
        }

        int i=0;
        int j=r.length()-1;
        while(i<j){
            if (r.charAt(i) != r.charAt(j)) {return false;}
            else{
                i++;
                j--;
            }
        }
        return true;
    }
}
