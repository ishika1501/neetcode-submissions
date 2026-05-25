class Solution {
public:
    int func(int n, int idx){
        if(idx==n)return 1;
        if(idx>n)return 0;
        int take=func(n, idx+1 );
        int nottake=func(n, idx+2);
        return take+nottake;
    }
    int climbStairs(int n) {
        return func(n ,0);
    }
};
