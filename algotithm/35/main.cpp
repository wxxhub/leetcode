#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }

        int start = 0;
        int size = nums.size();
        int end = size - 1;

        while (start < end) {
            int mid = (start + end) / 2;

            if (nums[mid] == target) {
                return mid;
            } else {
                if (target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                };
            }
        }

        if (target < nums[start] || target == nums[start]) {
            return start;
        }

        return start + 1;
    }
};

int main() {
    Solution solution;

//    vector<int> input = {1, 3, 5, 6};
//    cout << solution.searchInsert(input, 2);

//    vector<int> input = {1,3,5,6};
//    cout << solution.searchInsert(input, 7);

    vector<int> input = {1,3,5,6};
    cout << solution.searchInsert(input, 0);
    return 0;
}

/*
 *  1, 2, 4, 5
 *
 */