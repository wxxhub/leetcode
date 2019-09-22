#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result = "";

        if (num % 10 != 0) {
            result = Unit1[num % 10 - 1] + result;
        }

        num /= 10;

        if (num % 10 != 0) {
            result = Unit2[num % 10 - 1] + result;
        }

        num /= 10;

        if (num % 10 != 0) {
            result = Unit3[num % 10 - 1] + result;
        }

        num /= 10;

        if (num % 10 != 0) {
            result = Unit4[num % 10 - 1] + result;
        }

        return result;
    }

private:
    string Unit1[9] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string Unit2[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string Unit3[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string Unit4[3] = {"M", "MM", "MMM"};
};

int main() {
    Solution solution;

    int input;
    cin >> input;

    cout << solution.intToRoman(input) << endl;
    return 0;
}