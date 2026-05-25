class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c) {
        ocean[r][c] = true;
        for(auto dir: directions){
            int nr = r + dir[0], nc = c + dir[1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && 
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, ocean, nr, nc);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));


        for (int c = 0; c < cols; c++) 
        dfs(heights, pacific, 0, c);

        for (int r = 0; r < rows; r++) 
        dfs(heights, pacific, r, 0);


        for (int c = 0; c < cols; c++) 
        dfs(heights, atlantic, rows - 1, c);

        for (int r = 0; r < rows; r++) 
        dfs(heights, atlantic, r, cols - 1);

         vector<vector<int>> result;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;

    }
};
