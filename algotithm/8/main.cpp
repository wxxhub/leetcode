#include <iostream>

using namespace std;

//class Solution {
//public:
//    int myAtoi(string str) {
//        int max = 0x7fffffff;
//        int min = 0x80000000;
//        long result = 0;
//        int first_cha = 0;
//
//        for (int i = 0; i < str.size(); ++i) {
//            if (str[i] == ' ') {
//                if (first_cha != 0) {
//                    return first_cha * result;
//                }
//                continue;
//            }
//
//            if (first_cha == 0) {
//                if (str[i] == '-') {
//                    first_cha = -1;
//                    continue;
//                } else if (str[i] == '+') {
//                    first_cha = 1;
//                    continue;
//                } else if (str[i] >= '0' && str[i] <= '9'){
//                    first_cha = 1;
//                } else {
//                    return 0;
//                }
//            }
//
//            if (str[i] >= '0' && str[i] <= '9') {
//                result = result * 10 + (str[i] - '0');
//            } else {
//                if (result > max) {
//                    if (first_cha == -1) {
//                        return min;
//                    }
//                    return max;
//                } else {
//                    return first_cha * result;
//                }
//            }
//
//            if (result > max) {
//                if (first_cha == -1) {
//                    return min;
//                }
//                return max;
//            }
//        }
//
//        result = first_cha * result;
//
//        if (result < min) {
//            return min;
//        } else if (result > max) {
//            return  max;
//        }
//        return result;
//    }
//};

class Solution {
public:
    int myAtoi(string str) {
        int max = 0x7fffffff;
        int min = 0x80000000;
        long result = 0;
        int first_cha = 1;

        int index = 0;

        while (str[index] == ' ') {
            ++index;
        }

        if (index >= str.size()) {
            return 0;
        }

        if (str[index] == '-') {
            first_cha = -1;
            ++index;
        } else if (str[index] == '+') {
            ++index;
        } else if (str[index] < '0' || str[index] > '9') {
            return 0;
        }

        for (; index < str.size(); ++index) {
            if (str[index] >= '0' && str[index] <= '9') {
                if (result > max) {
                    break;
                }
                result = result * 10 + (str[index] - '0');
            } else {
                break;
            }
        }

        result *= first_cha;

        if (result < min) {
            return min;
        } else if (result > max) {
            return max;
        }

        return result;
    }
};

int main() {
    string input;
    Solution solution;
    cin >> input;
    std::cout << solution.myAtoi(input) << std::endl;
    return 0;
}
