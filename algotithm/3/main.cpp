#include <iostream>

using namespace std;

// other
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int  size,i=0,j,k,max=0;
        size = s.size();
        for(j = 0;j<size;j++){
            for(k = i;k<j;k++)
                if(s[k]==s[j]){
                    i = k+1;
                    break;
                }
            if(j-i+1 > max)
                max = j-i+1;
        }
        return max;
    }
};
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        for (int i = 0; i < 256; ++i) {
            cha_labels_[i].sit = -1;
            cha_labels_[i].exist = false;
        }

        int  size = s.size();
        int start = 0;
        int max_length = 0;
        for(int i = 0; i < size; ++i){
            if (cha_labels_[s[i]].exist) {
                int length = i - start;

                if (cha_labels_[s[i]].sit + 1 > start) {
                    start = cha_labels_[s[i]].sit + 1;
                }

                cha_labels_[s[i]].sit = i;

                if (length > max_length) {
                    max_length = length;
                }
            } else {
                cha_labels_[s[i]].exist = true;
                cha_labels_[s[i]].sit = i;
            }
        }

        if (size - start > max_length) {
            max_length = size - start;
        }
        return max_length;
    }

private:
    struct ChaLabel{
        int sit;
        bool exist;
    };

    ChaLabel cha_labels_[256];
};

int main() {
    string input;
    cin >> input;
    Solution solution;

    cout << solution.lengthOfLongestSubstring(input) << endl;

    return 0;
}