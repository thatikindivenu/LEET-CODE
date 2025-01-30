 class Solution {
 private:
 	bool dfs(vector<vector<char>>& board, int i_start, int j_start){
 		for(int i = 0; i < 9; ++i, j_start = 0){
 			for(int j = 0; j < 9; ++j){
 				if(board[i][j] != '.') continue;
 				for(char c = '1'; c <= '9'; ++c){
 					if(check(board, i, j, c)){
 						board[i][j] = c;
 						if(dfs(board, i, j + 1)) return true;
 						board[i][j] = '.';
 					}
 				}
 				return false;
 			}
 		}
 		return true;
 	}
 	bool check(vector<vector<char>>& board, int row, int col, char c){
 		for(int i = 0; i < 9; i++){
 			if(board[row][i] == c) return false;
 			if(board[i][col] == c) return false;
 			if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
 		}
 		return true;
 	}
 public:
 	void solveSudoku(vector<vector<char>>& board) {
 		dfs(board, 0, 0);
 	}
 };