#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";
        int unit_len = unitLen(numRows);
        int unit_size = s.size() / unit_len + 1;
        int start = 0;
        int end = unit_len;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j <= unit_size; ++j) {
                if (start == 0 || start >= end) {
                    int site = j * unit_len + start;
                    if (site < s.size()) {
                        result += s[site];
                    }
                } else {
                    int site1 = j * unit_len + start;
                    int site2 = j * unit_len + end;
                    if (site1 < s.size()) {
                        result += s[site1];
                    }
                    if (site2 < s.size()) {
                        result += s[site2];
                    }
                }
            }

            --end;
            ++start;
        }
        return  result;
    }

    // 计算一段的数量
    int unitLen(int numRows) {
        if (numRows == 1) {
            return  1;
        } else {
            return (numRows - 1) * 2;
        }
    }

};

int main() {
    Solution solution;

    cout << solution.convert("LEETCODEISHIRING", 1) << endl;
    return 0;
}