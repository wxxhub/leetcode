#include <iostream>
#include <list>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        if (s.size() % 2 == 1) {
            return false;
        }

        char pop;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case ')':
                    if (!charge(pop) || pop != '(') {
                        return false;
                    }
                    break;
                case ']':
                    if (!charge(pop) || pop != '[') {
                        return false;
                    }
                    break;
                case '}':
                    if (!charge(pop) || pop != '{') {
                        return false;
                    }
                    break;
                default:
                    stack_.push_front(s[i]);
                    break;
            }
        }

        if (!stack_.empty()) {
            return false;
        }
        return true;
    }

private:
    list<char> stack_;

    bool charge(char &c) {
        if (stack_.empty()) {
            return false;
        }

        c = *stack_.begin();
        stack_.pop_front();
        return true;
    }
};

// 没有提升速度和节省内存...
//class Solution {
//public:
//    bool isValid(string s) {
//
//        if (s.size() % 2 == 1) {
//            return false;
//        }
//
//        char c;
//        for (int i = 0; i < s.size(); ++i) {
//            switch (s[i]) {
//                case ')':
//                    if (!pop(c) || c != '(') {
//                        return false;
//                    }
//                    break;
//                case ']':
//                    if (!pop(c) || c != '[') {
//                        return false;
//                    }
//                    break;
//                case '}':
//                    if (!pop(c) || c != '{') {
//                        return false;
//                    }
//                    break;
//                default:
//                    push(s[i]);
//                    break;
//            }
//        }
//
//        if (index > 0) {
//            return false;
//        }
//        return true;
//    }
//
//private:
//    char stack_[1024];
//    u_int index = 0;
//    bool pop(char &c) {
//        if (index <= 0) {
//            return false;
//        }
//
//        c = stack_[--index];
//
//        return true;
//    }
//
//    void push(char &c) {
//        stack_[index++] = c;
//    }
//};

int main() {
    Solution solution;
    string input;
    cin >> input;
    cout << solution.isValid(input) << endl;
    return 0;
}