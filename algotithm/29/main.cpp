#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        // 过滤掉几种特殊情况
        if (divisor == 1) {
            return dividend;
        }

        if (dividend == divisor) {
            return 1;
        }

        if (divisor == -1) {
            if (dividend == -2147483648) {
                return 2147483647;
            } else {
                return 0 - dividend;
            }
        }

        // 如果 被除数为-2147483648, 且除数和被除数不等, 那么必定是0.
        if (divisor == -2147483648) {
            return 0;
        }

        // 获取符号(正负)
        int flag = (dividend ^ divisor) < 0 ? -1 : 1;

        int sum = 0;

        // 如果dividend == -2147483648, 那么无法直接变为正数, 可以先减一个被除数再变为正数.
        if (dividend == -2147483648) {
            dividend = divisor < 0 ? dividend - divisor : dividend + divisor;
            sum = 1;
        }

        // 将除数和被除数变正, 方便后续计算.
        int dividend2 = dividend < 0 ? 0 - dividend : dividend;
        int divisor2 = divisor < 0 ? 0 - divisor : divisor;
        int move_divisor2 = divisor2;

        // move记录左移的位数.
        int move = 0;

        // 采用位移的办法, 左移一位相当与乘2.
        while (dividend2 - move_divisor2 > move_divisor2) {
            ++move;
            move_divisor2 = move_divisor2 << 1;
        }

        while (dividend2 >= divisor2) {
            while (dividend2 >= move_divisor2) {
                // 相当于减去了多少倍, 就加上多少倍.
                dividend2 = dividend2 - move_divisor2;
                sum += 1 << move;
            }
            move_divisor2 = move_divisor2 >> 1;
            --move;
        }

        return flag < 0 ? 0 - sum : sum;
    }
};

int main() {
    Solution solution;
    cout << solution.divide(-2147483648, 2) << endl;
    return 0;
}