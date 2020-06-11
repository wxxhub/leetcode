#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int end = size - 1;
        int half_size = size / 2;

        /*
         *  a------b
         *  |      |
         *  |      |
         *  d------c
         */
        Point a, b, c, d;

        for (int i = 0; i < half_size; i++) {
            resetPoint(a, b, c, d, i, end);

            int move_times = end - i * 2 ;

            for (int j = 0; j < move_times; j++) {
                int cache = matrix[d.y][d.x];

                matrix[d.y][d.x] = matrix[c.y][c.x];
                matrix[c.y][c.x] = matrix[b.y][b.x];
                matrix[b.y][b.x] = matrix[a.y][a.x];
                matrix[a.y][a.x] = cache;
                movePoint(a, b, c, d);
            }
        }

    }

private:
    void resetPoint(Point &a, Point &b, Point &c, Point &d, const int &i, const int &end) {
        a.x = i;
        a.y = i;

        b.x = end - i;
        b.y = i;

        c.x = end - i;
        c.y = end - i;

        d.x = i;
        d.y = end - i;
    }

    void movePoint(Point &a, Point &b, Point &c, Point &d) {
        a.x++;
        b.y++;
        c.x--;
        d.y--;
    }
};

int main() {
    vector<vector<int>> input = {{1, 2, 3, 4},
                                 {5, 6, 7, 8},
                                 {9, 10, 11, 12},
                                 {13, 14, 15, 16}};

    Solution solution;

    solution.rotate(input);
    return 0;
}
