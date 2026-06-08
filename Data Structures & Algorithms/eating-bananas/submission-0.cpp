class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int left=1;
        int right=*max_element(piles.begin(), piles.end());

        int ans=right;

        while(left<=right){
            int mid=left+(right-left)/2;
            int hrs=0;

            for(auto it: piles){
                hrs += (it + mid - 1) / mid;
            }
                if(hrs<=h){
                    ans=mid;
                    right=mid-1;
                }else{
                    left=mid+1;
                }
        }
        return ans;
    }
};
