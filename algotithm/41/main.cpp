#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 1;
        }

        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                while (nums[i] > 0 && nums[i] != i + 1 && nums[i] < size) {
                    int temp = nums[i];

                    if (temp == nums[temp-1]) {
                        break;
                    }

                    nums[i] = nums[temp - 1];
                    nums[temp - 1] = temp;
                }
            }
        }

        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return size + 1;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {7, 8, 9, 11, 12};

    cout << solution.firstMissingPositive(nums) << endl;
    return 0;
}
