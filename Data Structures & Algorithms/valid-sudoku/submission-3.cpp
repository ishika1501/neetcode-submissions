class Solution {
public:
    // bool isValid(vector<vector<char>>& board, int row, int col, char num){
    //     for (int j = 0; j < 9; j++) {
    //         if (board[row][j] == num)return false;
    //     }
    //     for(int i=0; i<9; i++){
    //         if(board[i][col]==num)return false;
    //     }
    //     int startRow = (row / 3) * 3;
    //     int startCol = (col / 3) * 3;

    //     for (int i = startRow; i < startRow + 3; i++) {
    //         for (int j = startCol; j < startCol + 3; j++) {

    //             if (board[i][j] == num)
    //                 return false;
    //         }
    //     }
    //     return true;
    // }

    // bool solve(vector<vector<char>>& board){
    //     for (int row = 0; row < 9; row++) {
    //         for (int col = 0; col < 9; col++) {
    //             if (board[row][col] == '.'){
    //                 for (char num = '1'; num <= '9'; num++){
    //                     if (isValid(board, row, col, num)){
    //                         board[row][col]=num;
    //                         if(solve(board))return true;
    //                         board[row][col]='.';
    //                     }
    //                 }
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    bool isValidSudoku(vector<vector<char>>& board) {
        //return solve(board);
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxes(9, vector<bool>(9, false));

        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.')continue;
                int digit = board[r][c] - '1';
                int box = (r / 3) * 3 + (c / 3);

                if (rows[r][digit] || cols[c][digit] || boxes[box][digit]) {
                    return false;
                }

                rows[r][digit] = true;
                cols[c][digit] = true;
                boxes[box][digit] = true;
            }
        }
        return true;
    }
};
