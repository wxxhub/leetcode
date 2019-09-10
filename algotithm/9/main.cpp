#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long x_back = x;
        long match = 0;

        for (; x != 0; x /= 10) {
            match = match * 10 + x % 10;
        }

        return  x_back == match;
    }
};

int main() {
    Solution solution;
    int x;
    cin >> x;
    cout << solution.isPalindrome(x) << endl;
    return 0;
}