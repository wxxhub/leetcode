#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        int max = 0x7fffffff, min = 0x80000000;
        long rs = 0;
        while(x != 0)
        {
            rs = rs * 10 + x % 10;
            if (rs>max || rs<min) {
                return 0;
            }

            x /= 10;
        }
        return rs;
    }
};

int main() {
    Solution solution;
    int input;
    cin >> input;
    std::cout << solution.reverse(input) << std::endl;
    return 0;
}

/*
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321

 示例 2:

输入: -123
输出: -321

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */