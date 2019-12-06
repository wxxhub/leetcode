#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        if (needle.size() > haystack.size()) {
            return -1;
        }

        vector<int> next = getNext(needle);
        int i = 0;
        int j = 0;
        int size1 = haystack.size();
        int size2 = needle.size();
        while (i < size1 && j < size2) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }

        if (j == needle.size()) {
            return i - j;
        } else {
            return -1;
        }
    }

    vector<int> getNext(string needle) {
        vector<int> next(needle.size());

        next[0] = -1;
        int i = 0, k = -1;

        while (i < needle.size() - 1) {
            if (k == -1 || needle[i] == needle[k]) {
                ++i;
                ++k;
                next[i] = k;
            } else {
                k = next[k];
            }

        }
        return next;
    }
};

int main() {
    Solution solution;
    int result = solution.strStr("hello", "ll");
    cout << "s: " << result << endl;
    return 0;
}

/*
 * a  b  c  a  b  b
 * -1 0  -1 0  1  0
"mississippi"
"pi"

"aabaaabaaac"
"aabaaac"

 a  a b a a a c
 -1 0 1 0 1 2 2 0
 */