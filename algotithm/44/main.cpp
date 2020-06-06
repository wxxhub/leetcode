#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p == "*" || p == s) {
            return true;
        }

        if (p == "") {
            return s == "" ? true : false;
        }

        int p_size = p.size();

        for (int i = 0; i < p_size; i++) {

        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
