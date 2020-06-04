#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() :
        value_size_(30) {
        init();
    }

    string countAndSay(int n) {
        return values_[n-1];
    }

private:
    const int value_size_;
    void init() {
        values_.push_back("1");

        int index = 1;
        setValue(index);
    }

    void setValue(int &index) {

        if (index < value_size_) {
            int size = values_[index-1].size();
            char last_char = values_[index-1][0];
            int num = 1;
            string current_value_ = "";
            for (int i = 1; i < size; i++) {
                if (values_[index-1][i] == last_char) {
                    num++;
                }
                else {
                    char value[2];
                    sprintf(value, "%d%c", num, last_char);
                    current_value_ += value;
                    num = 1;
                    last_char = values_[index-1][i];
                }
            }

            char value[2];
            sprintf(value, "%d%c", num, last_char);
            current_value_ += value;

            values_.push_back(current_value_);

            index++;
            setValue(index);
        }
    }

    vector<string> values_;
};

int main() {
    Solution solution;

    cout << solution.countAndSay(5) << endl;
    return 0;
}
