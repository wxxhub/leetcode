#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 || n == 1) {
            return x;
        }

        if (n == 0) {
            return 1;
        }

        double check = 1.0;

        if (n < 0) {
            x = 1 / x;

            if (n == 0x80000000) {
                n = -(n + 1);
                check = x;
            } else {
                n = -n;
            }
        }

        return check * halfProcess(x, n);
    }

    double halfProcess(double x, int n) {
        if (n == 1) {
            return x;
        }

        double result = x;
        int d = 1;
        n--;

        // 看还够不够
        while (n > d) {
            result *= result;

            n -= d;
            d *= 2;
        }

        if (n) result *= halfProcess(x, n);

        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.myPow(2, 10) << endl;
    return 0;
}
