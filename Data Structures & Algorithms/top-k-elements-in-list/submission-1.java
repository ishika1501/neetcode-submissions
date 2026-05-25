class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n=nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int num : nums) {
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
            }
        }
        
        PriorityQueue<int[]>pq=new PriorityQueue<>((a,b)->a[1]-b[1]);

        for(int num:map.keySet()){
            int freq=map.get(num);
            int[] pair= new int[2];
            pair[0]=num;
            pair[1]=freq;

            pq.offer(pair);
            if(pq.size()>k)pq.poll();
        }

        int[] ans = new int[k];

        for(int i=k-1; i>=0; i--){
            int[] top=pq.poll();
            ans[i]=top[0];
        }

        return ans;
    }   

}
