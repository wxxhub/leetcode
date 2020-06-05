#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        if (num1 == "1") {
            return num2;
        }

        if (num2 == "1") {
            return num1;
        }

        string result = "";

        int num2_size = num2.size();

        for (int i = 0; i < num2_size; i++) {
            process(num1, num2[num2_size - i - 1], i, result);
        }
        reverse(result.begin(), result.end());

        return result;
    }

    void process(string &num1, char &num2_c, int i, string &result) {
        string temp = "";
        int size = num1.size();
        char c;
        int carry = 0;
        for (int j = 0; j < size; j++) {
            multiply_char(num1[size - j - 1], num2_c, c, carry);
            temp += c;
        }

        if (carry) {
            temp += carry + '0';
        }

        carry = 0;
        size = temp.size();
        int result_size = result.size();
        for (int j = 0; j < size; j++, i++) {
            if (i < result_size) {
                int value = (result[i] - '0') + (temp[j] - '0') + carry;
                result[i] = (value % 10) + '0';
                carry = value >= 10 ? 1 : 0;
            } else {
                int value = (temp[j] - '0') + carry;
                result += (value % 10) + '0';
                carry = value >= 10 ? 1 : 0;
            }
        }

        if (carry) {
            result += '1';
        }
    }

    void multiply_char(const char &a, const char &b, char &c, int &carry) {
        int result = (a - '0') * (b - '0') + carry;

        c = '0' + (result % 10);

        carry = result / 10;
    }
};

int main() {
    Solution solution;

    cout << solution.multiply("9", "9") << endl;
    return 0;
}

/*
 *   738
 *  615
 * 492
 */