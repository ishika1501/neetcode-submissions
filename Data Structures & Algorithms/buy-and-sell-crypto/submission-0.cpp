class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int l=0, r=1;
        int maxp=0;
        int profit=0;
        while(r<n){
            if(prices[l]<prices[r]){
                profit=prices[r]-prices[l];
                maxp = max(maxp, profit);
            }else{
                l=r;
            }
            r++;
        }
        return maxp;
    }
};
