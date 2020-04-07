#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        if (nums.empty()) {
            return result;
        }

        int start = 0;
        int size = nums.size();
        int end = size - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                int left = mid;
                int right = mid;
                while (left-1 >= 0) {
                    if (nums[left-1] != target) {
                        break;
                    }
                    left--;
                }

                while (right+1 < size) {
                    if (nums[right+1] != target) {
                        break;
                    }
                    right++;
                }
                result[0] = left;
                result[1] = right;
                break;
            } else {
                if (target < nums[mid]) {
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
//    vector<int> input = {5, 7, 7, 8, 8, 10};
//
//    vector<int> result = solution.searchRange(input, 8);

//    vector<int> input = {2, 2};
//
//    vector<int> result = solution.searchRange(input, 1);

    vector<int> input = {1};

    vector<int> result = solution.searchRange(input, 1);
    cout << result[0] << "," << result[1] << endl;
    return 0;
}
