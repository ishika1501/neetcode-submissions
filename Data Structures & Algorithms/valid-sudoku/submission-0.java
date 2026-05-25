class Solution {
    boolean func(int row , int col ,char[][] board){
        char ch = board[row][col];
        for (int j = 0; j < 9; j++) {
            if (j != col && board[row][j] == ch) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] == ch) {
                return false;
            }
        }

        int startrow=(row/3)*3;
        int startcol=(col/3)*3;

        for(int i=startrow ; i<startrow+3; i++){
            for(int j=startcol; j<startcol+3; j++){
                if ((i != row || j != col) && board[i][j] == ch) {
                    return false;
                }
            }
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
        int n=board.length;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]!='.'){
                    if(!func(i, j, board))return false;
                }
            }
        }
        return true;
    }
}
