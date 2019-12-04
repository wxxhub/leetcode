#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }

        int i = 0;
        int j = 0;
        int size = nums.size();
        for (;j < size; ++j) {
            if (nums[j] != val) {
                nums[i++] = nums[j];
            }
        }

        return i;
    }
};

int main() {
    vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution solution;
    int n = solution.removeElement(input, 1);
    for (int i = 0; i < n; ++i) {
        cout << input[i] << " ";
    }

    return 0;
}