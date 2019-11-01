#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int l_flag = n - 1;     // 左括号剩余数量
        int r_flag = n;         // 右括号剩余数量
        string data = "(";
        function(l_flag, r_flag, data, result);
        return result;
    }

private:
    void function(int l_flag, int r_flag, string data, vector<string> &result) {

        // 当左括号没有, 右括号还剩一个时.
        if (r_flag == 1 && l_flag == 0) {
            result.push_back(data + ")");
            return;
        }

        // 如果左括号有剩余, 并且小于等于右括号数量.
        if (l_flag > 0 && l_flag <= r_flag) {
            function(l_flag - 1, r_flag, data + "(", result);
        }

        // 如果右括号剩余数量大于1, 右括号数量多余左括号.
        if (r_flag > 1 && r_flag > l_flag) {
            function(l_flag , r_flag - 1, data + ")", result);
        }
    }
};

// 并没有节省内存和时间....
//class Solution {
//public:
//    vector<string> generateParenthesis(int n) {
//        vector<string> result;
//        if (n == 1) {
//            result.push_back("()");
//            return result;
//        }
//        int l_flag = n - 1;     // 左括号剩余数量
//        int r_flag = n;         // 右括号剩余数量
//        int flag = 0;
//        int size = n * 2 - 2;
//        function(l_flag, r_flag, flag, result, size);
//        return result;
//    }
//
//private:
//    void function(int l_flag, int r_flag, int flag, vector<string> &result, const int &size) {
//
//        // 当左括号没有, 右括号还剩一个时.
//        if (r_flag == 1 && l_flag == 0) {
//            string data = "(";
//            int t = 1 << size - 1;
//            for (int i = size; i > 0; --i) {
//                if ((t & flag) == 0) {
//                    data += ")";
//                } else {
//                    data += "(";
//                }
//                t = t >> 1;
//            }
//
//            data += ")";
//            result.push_back(data);
//            return;
//        }
//
//        // 如果左括号有剩余, 并且小于等于右括号数量.
//        if (l_flag > 0 && l_flag <= r_flag) {
//            function(l_flag - 1, r_flag, (flag << 1) + 1, result, size);
//        }
//
//        // 如果右括号剩余数量大于1, 右括号数量多余左括号.
//        if (r_flag > 1 && r_flag > l_flag) {
//            function(l_flag , r_flag - 1, flag << 1, result, size);
//        }
//    }
//};

int main() {
    Solution solution;

    vector<string> result = solution.generateParenthesis(3);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}