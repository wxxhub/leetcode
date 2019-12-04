#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int i = 0;
        int j = 0;
        int flag = nums.size() - 1;
        while (j < flag) {
            if (nums[j] != nums[++j]) {
                nums[++i] = nums[j];
            }
        }

        return i + 1;
    }
};

int main() {
    vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution solution;
    int n = solution.removeDuplicates(input);
    for (int i = 0; i < n; ++i) {
        cout << input[i] << " ";
    }
    return 0;
}