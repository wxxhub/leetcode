#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int end = s.size();
        int current_len = 0;

        int l = 0;
        int i = 0;
        for (; i < end; i++) {
            if (s[i] == '(') {
                break;
            }
        }

        for (; end > i; end--) {
            if (s[end-1] == ')') {
                break;
            }
        }

        int start = i;
        vector<int> test;
        for (; i < end; i++) {
            if (s[i] == '(') {
                test.push_back(i);
            } else {
                if (!test.empty()) {
                    s[i] = 'y';
                    int j = *(test.end() - 1);
                    test.pop_back();
                    s[j] = 'y';
                }
            }
        }

        for (; start < end; start++) {
            if (s[start] == 'y') {
                current_len++;
            } else {
                if (current_len > result) {
                    result = current_len;
                }
                current_len = 0;
            }

        }

        if (current_len > result) {
            result = current_len;
        }

        return result;
    }
};

int main() {
    Solution solution;
    string input;
    cin >> input;
    cout << solution.longestValidParentheses(input) << endl;
    return 0;
}
