#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        int end = nums.size() - 1;

        vector<int> cache;
        
        process(result, cache, nums, 0, end);
        
        return result;
    }

    void process(vector<vector<int>> &result, vector<int> &cache, vector<int> nums, int start, int end) {
        if (end < start) {
            result.push_back(cache);
            return;
        }

        for (int i = start; i <= end; i++) {
            int mid = nums[start];
            nums[start] = nums[i];
            nums[i] = mid;

            cache.push_back(nums[start]);
            process(result, cache, nums, start + 1, end);
            cache.pop_back();
        }
    }
};

int main() {
    Solution solution;

    vector<int> input = {1, 2, 3};

    solution.permute(input);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
