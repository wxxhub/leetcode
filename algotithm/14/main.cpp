#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        if (strs.empty()) {
//            return "";
//        }
//
//        int max_same = maxSame(strs);
//
//        return strs[0].substr(0, max_same);
//    }
//
//    int maxSame(vector<string>& strs) {
//        long longs = 0;
//        int min_size = strs[0].size();
//
//        // 字符串最后一位为 '\0'
//        for (int i = 0; i < min_size; ++i) {
//            vector<string>::iterator iter = strs.begin();
//
//            char t = strs[0][i];
//
//            for (++iter; iter != strs.end(); ++iter) {
//                if ((*iter)[i] != t) {
//                    return longs;
//                }
//            }
//
//            ++longs;
//        }
//
//        return longs;
//    }
//};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        int max_same = maxSame(strs);

        return strs[0].substr(0, max_same);
    }

    int maxSame(vector<string>& strs) {
        long longs = 0;
        int min_size = strs[0].size();

        vector<string>::iterator iter = strs.begin();
        for (++iter; iter != strs.end(); ++iter) {
            if (min_size > iter->size()) {
                min_size = iter->size();
            }
        }

        for (int i = 0; i < min_size; ++i) {
            vector<string>::iterator iter = strs.begin();

            char t = strs[0][i];

            for (++iter; iter != strs.end(); ++iter) {
                if ((*iter)[i] != t) {
                    return longs;
                }
            }

            ++longs;
        }

        return longs;
    }
};


int main() {
    Solution solution;

    vector<string> strs = {"aab","aa","aa"};

    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}