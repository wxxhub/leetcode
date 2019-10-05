#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if (!digits.empty()) {
            push(result, 0, digits, "", digits.size());
        }

        return result;
    }

private:
    void push(vector<string> &result, int layer, string &digits, string temp, const int &size) {
        if (layer == size) {
            result.push_back(temp);
        } else {
            int button = digits[layer] - '2';
            for (int i = 0; i < buttons[button].size(); ++i) {
                string temp2 = temp + buttons[button][i];
                push(result, layer + 1, digits, temp2, digits.size());
            }
        }
    }
    string buttons[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

int main() {
    Solution solution;

    string input;

    cin >> input;

    vector<string> result = solution.letterCombinations(input);

    for (int i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"" << endl;
    }
    return 0;
}