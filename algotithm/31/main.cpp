#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;

        for (; i > 0; --i) {
            if (nums[i] > nums[i-1]) {
                sort(nums.begin() + i, nums.end());
                int m = nums[i - 1];

                for (int j = i; j < nums.size(); ++j) {
                    if (m < nums[j]) {
                        nums[i - 1] = nums[j];
                        nums[j] = m;
                        return;
                    }
                }
            }
        }

        reverse(nums.begin(), nums.end());
    }
};

int main() {
//    vector<int> input = {1,2,3,1,5,4,3,2,1};
    vector<int> input = {2,1,2,2,2,2,2,1};
    Solution solution;
    solution.nextPermutation(input);
    for (int i = 0; i < input.size(); ++i) {
        cout << input[i] << " ";
    }
    return 0;
}

// [2,1,2,2,2,2,2,1]