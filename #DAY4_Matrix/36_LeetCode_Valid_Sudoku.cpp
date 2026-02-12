#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> box(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1';
                int boxIndex = (i / 3) * 3 + (j / 3);

                if (row[i][num] || col[j][num] || box[boxIndex][num])
                    return false;

                row[i][num] = 1;
                col[j][num] = 1;
                box[boxIndex][num] = 1;
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter Sudoku board (use . for empty cells):\n";

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;

    if (obj.isValidSudoku(board))
        cout << "Valid Sudoku\n";
    else
        cout << "Invalid Sudoku\n";

    return 0;
}

//Leetcode Link:-https://leetcode.com/submissions/detail/1917010772/