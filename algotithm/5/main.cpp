#include <iostream>
#include <string>

using namespace std;

// plan 1
/*
class Solution {
public:
    string longestPalindrome(string s)
	{
		if (s.length() < 1)
		{
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length(); i++)
		{
			int len1 = expandAroundCenter(s, i, i);//一个元素为中心
			int len2 = expandAroundCenter(s, i, i + 1);//两个元素为中心
			int len = max(len1, len2);
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{// 计算以left和right为中心的回文串长度
			L--;
			R++;
		}
		return R - L - 1;
	}

};
 */

// plan 2 no pass
class Solution {
public:
    string longestPalindrome(string s) {

        string result = "";

        int max_len = 1;
        int size = s.size();

        for (int i = 0; i < size; ++i) {
            int len = 0;
            int label = 0;
            int last_sit = i;
            bool first_same = false;

            for (int j = 1; j <= size; ++j) {
                int current_sit = i + move(j);

                if (current_sit < 0 || current_sit >= size) {
                    if (label == 0) {
                        len = j;
                    }
                    break;
                }

                if (s[last_sit] == s[current_sit]) {
                    label = 0;
                    if (j == 1) {
                        first_same = true;
                    }
                } else {
                    if (label == 0) {
                        len = j;
                    }
                    ++label;
                    if (label >= 2) {
                        break;
                    }
                }

                last_sit = current_sit;
            }

            if (!first_same && len % 2 == 0) {
                len -= 1;
            }
            if (len > result.size()) {
                result = "";

                int l1 = move(len - 1);
                int l2 = move(len - 2);

                cout << "len: " << len << " l1:" << l1 << " l2:" << l2 << endl;
                if (l1 < l2) {
                    int other_same = 1;
                    char key = s[i + l1];
                    for (int k = i + l1 + 1; k <= i +l2; ++k) {
                        result += s[k];

                        if (first_same  && s[k] == key) {
                            ++other_same;
                        }
                    }

                    if (first_same && (other_same % 2 == 0 || other_same == 1)) {
                        result = key + result;
                    } else if (!first_same) {
                        result = key + result;
                    }
                } else {
                    int other_same = 1;
                    char key = s[i + l2];
                    for (int k = i + l2; k <= i + l1 -1; ++k) {
                        result += s[k];

                        if (first_same  && k !=  i + l2 && s[k] == key) {
                            ++other_same;
                        }
                    }

                    if (first_same && (other_same % 2 == 0 || other_same == 1)) {
                        result = result + s[i + l1];
                    } else if (!first_same) {
                        result = result + s[i + l1];
                    }
                }
            }
        }
        return  result;
    }

    int move(int times) {
        int m;
        if (times < 0) {
            return 0;
        }

        if (times % 2 == 0) {
            m = -1 * times / 2;
        } else {
            m = (times + 1) / 2;
        }

        return m;
    }
};

int main() {
    Solution solution;
    string input;
    cin >> input;
    cout << solution.longestPalindrome(input) << endl;
    return 0;
}