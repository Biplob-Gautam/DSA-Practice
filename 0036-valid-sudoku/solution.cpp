class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]!='.' && !isValid(board,i,j)) return false;
            }
        }
        return true;
    }

private:
    bool isValid(vector<vector<char>> &board , int r, int c){
        char ch = board[r][c];

        for(int i=0; i<board.size(); i++){

            //for each row --> check in 1st col
            if(i!=r && board[i][c]==ch) return false;    //keeping col constant

            //for each col --> check in 1st row
            if(i!=c && board[r][i]==ch) return false;   //keeping row constant

            //for each 3x3 grid -->  use mathematical formula
            int selected_row=3*(r/3) + i/3;
            int selected_col=3*(c/3) + i%3;

            if(selected_row == r && selected_col == c) continue;  //check if selscted is same as sent parameter bcz then the value will obviously be same
            if(board[selected_row][selected_col]==ch) return false;
        }
        return true;
    }
};
