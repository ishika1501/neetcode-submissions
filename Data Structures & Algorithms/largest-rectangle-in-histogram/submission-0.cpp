class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int h=heights[i];
            int left = i;
            int right = i;

            while (left - 1 >= 0 && heights[left - 1] >= h)left--;
            while (right + 1 < n && heights[right + 1] >= h) right++;

            ans=max(ans, ((right-left+1)*h));
        }
        return ans;
    }
};
