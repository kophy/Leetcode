class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, ' '));
        for (int i = 0; i < moves.size(); ++i) {
            char c = (i % 2 == 0)? 'X' : 'O';
            const auto &move = moves[i];
            board[move[0]][move[1]] = c;
            
            if (isWinner(board, 'X')) {
                return "A";
            }
            if (isWinner(board, 'O')) {
                return "B";
            }
        }
        
        return moves.size() < 9? "Pending" : "Draw";
    }

private:
    bool isWinner(vector<vector<char>> &board, int c) {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c) {
                return true;
            }
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c) {
                return true;
            }
        }
        
        if (board[0][0] == c && board[1][1] ==c && board[2][2] == c) {
            return true;
        }
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c) {
            return true;
        }
        return false;
    }
};