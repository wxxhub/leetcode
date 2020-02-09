#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        max_len = 0;
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
                update_max(current_len);
                current_len = 0;
            }

        }

        update_max(current_len);
        return max_len;
    }

private:
    int max_len;
    void update_max(int len) {
        if (len > max_len) {
            max_len = len;
        }
    }
};

int main() {
    Solution solution;
    string input;
    cin >> input;
    cout << solution.longestValidParentheses(input) << endl;
    return 0;
}
