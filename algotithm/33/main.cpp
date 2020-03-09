#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = nums.size() / 2;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            if (nums[mid] == target) {
                return mid;
            } else {
                if (nums[mid] <= nums[end]) { // 右边有序
                    if (target < nums[mid]) { // 右边有序, 如果target < nums[mid]， 那么右边的都比target大,那么target可能在左边
                        end = mid - 1;
                        mid = (start + end) / 2;
                    } else { // 右边有序, 如果target > nums[mid], 那么需要再次判断方向, 如果nums[end] < target, 那么右边都比target小，则target可能左边，否则在右边
                        if (nums[end] < target) {
                            end = mid - 1;
                            mid = (start + end) / 2;
                        } else {
                            start = mid + 1;
                            mid = (start + end) / 2;
                        }
                    }
                } else { // 右边非有序， 左边一定有序
                    if (target > nums[mid]) { // 左边有序, 如果target > nums[mid]， 那么左边的都比target小,那么target可能在右边
                        start = mid + 1;
                        mid = (start + end) / 2;
                    } else { // 左边有序, 如果target < nums[mid], 那么需要再次判断方向, 如果nums[start] > target, 那么左边都比target大，则target可能右边，否则在左边
                        if (nums[start] > target) {
                            start = mid + 1;
                            mid = (start + end) / 2;
                        } else {
                            end = mid - 1;
                            mid = (start + end) / 2;
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> test = {2,3,4,5,6,7,8,9,1};
    std::cout << solution.search(test, 9) << std::endl;
    return 0;
}

// {7, 0, 1, 2, 4, 5, 6}
// {4, 0, 1, 2}