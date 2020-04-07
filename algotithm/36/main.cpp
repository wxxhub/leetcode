#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // cols check
        for(int i = 0; i < 9; i++) {
            bool check[9] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                int check_site = board[i][j] - '1';
                if (check[check_site]) {
                    return false;
                } else {
                    check[check_site] = true;
                }
            }
        }

        // cols check
        for(int i = 0; i < 9; i++) {
            bool check[9] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }

                int check_site = board[j][i] - '1';
                if (check[check_site]) {
                    return false;
                } else {
                    check[check_site] = true;
                }
            }
        }

        // 3x3
        for (int i = 0; i < 9; i++) {
            int col = (i % 3) * 3;
            int row = (i / 3) * 3;

            bool check[9] = {0};
            for (int j = 0; j < 9; j++) {
                int current_col = col + j % 3;
                int current_row = row + j / 3;
                if (board[current_row][current_col] == '.') {
                    continue;
                }

                int check_site = board[current_row][current_col] - '1';
                if (check[check_site]) {
                    return false;
                } else {
                    check[check_site] = true;
                }
            }
        }

        return true;
    }
};

int main() {
    vector<vector<char>> input = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'},
    };

//    for (int i = 0; i < input.size(); i++) {
//        for (int j = 0; j < input[i].size(); j++) {
//            cout << input[i][j] << ";";
//        }
//
//        cout << endl;
//    }

    Solution solution;
    cout << solution.isValidSudoku(input) << endl;
    return 0;
}

/*
{'.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.'},
 */