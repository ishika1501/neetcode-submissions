class Solution {
    public int longestConsecutive(int[] nums) {
        int i=0, j=0;
        HashSet<Integer>set= new HashSet<>();
        for(int num: nums)set.add(num);
        int ans=0;
        for(int num: set){
            if(!set.contains(num-1)){
                int currnum=num;
                int count=1;

                while(set.contains(currnum+1)){
                    count++;
                    currnum++;
                }
                ans=Math.max(ans, count);
            }
        }
        return ans;
    }
}
