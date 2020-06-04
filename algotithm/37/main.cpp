#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>

using namespace std;

struct Site {
    int x;
    int y;
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        init();

        vector<Site> empty_site;

        while (update(board, empty_site) != 0) {
            vector<Site>::iterator iter = empty_site.begin();

            for (; iter != empty_site.end(); iter++) {
                vector<int> possible_set;
                vector<int> possible_set2;
                set_intersection(row_data_[iter->x].begin(), row_data_[iter->x].end(), col_data_[iter->y].begin(), col_data_[iter->y].end(), back_inserter(possible_set));

                int range_sit = getRangeSite(iter->x, iter->y);
                set_intersection(possible_set.begin(), possible_set.end(), range_data_[range_sit].begin(), range_data_[range_sit].end(), back_inserter(possible_set2));

                if (possible_set2.size() == 1) {
                    board[iter->x][iter->y] = '0' + possible_set2[0];
//                    cout << iter->x << ":" << iter->y << ":" << possible_set2[0] << ":" << board[iter->x][iter->y] << endl;
                } else {
                    int size2 = possible_set2.size();

                    for (int i = 0; i < size2; i++) {
                        // 如果不肯在其他地方出现，则填入
                        if (!possibleInOther(iter->x, iter->y, possible_set2[i], board)) {
                            board[iter->x][iter->y] = '0' + possible_set2[i];
                            break;
                        }
                    }
                }


            }

            cout << "##" << endl;
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    cout << board[i][j] << ";";
                }

                cout << endl;
            }
        }
    }

    bool possibleInOther(const int &x, const int &y, const int &value, vector<vector<char>>& board) {
//        bool result = false;
        bool row_result = false;
        bool col_result = false;
        int start_x = int(x/3) * 3;
        int start_y = int(y/3) * 3;
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == '.') {
                if (i == x) {
                    continue;
                }
                auto find_result = col_data_[i].find(value);
                if (find_result != col_data_[i].end()) {
                    row_result = true;
                }
            }

            if (board[x][i] == '.') {
                if (i == y) {
                    continue;
                }
                auto find_result = row_data_[i].find(value);
                if (find_result != row_data_[i].end()) {
                    col_result = true;
                }
            }
        }

        if (x == 0 && y == 8) {
            cout << row_result << col_result << endl;
        }
        return (row_result && col_result);
    }

    int getRangeSite(int x, int y) {
        return int(x / 3) + int(y/3) * 3;
    }

    int update(vector<vector<char>>& board, vector<Site>& empty_site) {
        row_data_.assign(origin_data_.begin(), origin_data_.end());
        col_data_.assign(origin_data_.begin(), origin_data_.end());
        range_data_.assign(origin_data_.begin(), origin_data_.end());

        empty_site.clear();

        int empty_sum = 0;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int value = board[i][j] - '0';
                    row_data_[i].erase(value);
                    col_data_[j].erase(value);
                    range_data_[getRangeSite(i, j)].erase(value);
                } else {
                    Site site;
                    site.x = i;
                    site.y = j;
                    empty_site.push_back(site);
                    empty_sum++;
                }
            }
        }

        return empty_sum;
    }

private:

    void init() {
        set<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};

//        origin_data_.reserve(10);

        for (int i = 0; i < 9; i++) {
            origin_data_.push_back(data);
        }
    }

    vector<set<int>> row_data_;
    vector<set<int>> col_data_;
    vector<set<int>> range_data_;

    vector<set<int>> origin_data_;
};

int main() {
//    vector<vector<char>> input = {
//            {'5','3','.','.','7','.','.','.','.'},
//            {'6','.','.','1','9','5','.','.','.'},
//            {'.','9','8','.','.','.','.','6','.'},
//            {'8','.','.','.','6','.','.','.','3'},
//            {'4','.','.','8','.','3','.','.','1'},
//            {'7','.','.','.','2','.','.','.','6'},
//            {'.','6','.','.','.','.','2','8','.'},
//            {'.','.','.','4','1','9','.','.','5'},
//            {'.','.','.','.','8','.','.','7','9'},
//    };

    vector<vector<char>> input = {
            {'.','.','9','7','4','8','.','.','.'},
            {'7','.','.','.','.','.','.','.','.'},
            {'.','2','.','1','.','9','.','.','.'},
            {'.','.','7','.','.','.','2','4','.'},
            {'.','6','4','.','1','.','5','9','.'},
            {'.','9','8','.','.','.','3','.','.'},
            {'.','.','.','8','.','3','.','2','.'},
            {'.','.','.','.','.','.','.','.','6'},
            {'.','.','.','2','7','5','9','.','.'}
    };

    Solution solution;
    solution.solveSudoku(input);

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            cout << input[i][j] << ";";
        }

        cout << endl;
    }
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

//[[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]]