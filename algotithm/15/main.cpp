#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        // 从小到大排序
//        sort(nums.begin(), nums.end());
//
//        vector<vector<int>> result;
//
//        int t1_end = -1;
//        int t2_start = nums.size();
//        int zero_size = 0;
//
//        vector<int>::iterator iter = nums.begin();
//
//        for (; iter != nums.end(); ++iter) {
//            if (*iter < 0) {
//                t1_end = iter - nums.begin();
//            } else if (*iter == 0) {
//                ++zero_size;
//            } else {
//                t2_start = iter - nums.begin();
//                break;
//            }
//        }
//
//        if (zero_size >= 3) {
//            vector<int> zeros = {0, 0 , 0};
//            result.push_back(zeros);
//        }
//
//        if (t1_end == -1 || t2_start == nums.size()) {
//            return result;
//        }
//
//        // 存在0的情况
//        if (zero_size > 0) {
//            int i = t1_end;
//            int j = t2_start;
//
//            while (i >= 0 && j < nums.size()) {
//                if (nums[i] + nums[j] == 0) {
//                    vector<int> temp = {nums[i], 0 , nums[j]};
//                    result.push_back(temp);
//
//                    ++j;
//                    --i;
//                } else if (nums[i] + nums[j] < 0) {
//                    ++j;
//                } else {
//                    --i;
//                }
//            }
//        }
//
//        // 排除掉0
//
//
//        return result;
//    }
//};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 从小到大排序
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int t1_end = -1;
        int t2_start = nums.size();
        int size = nums.size();
        int zero_size = 0;

        vector<int>::iterator iter = nums.begin();

        for (; iter != nums.end(); ++iter) {
            if (*iter < 0) {
                t1_end = iter - nums.begin();
            } else if (*iter == 0) {
                ++zero_size;
            } else {
                t2_start = iter - nums.begin();
                break;
            }
        }

        if (zero_size >= 3) {
            vector<int> zeros = {0, 0 , 0};
            result.push_back(zeros);
        }

        if (t1_end == -1 || t2_start == size) {
            return result;
        }

        // 存在0的情况
        if (zero_size > 0) {
            int i = t1_end;
            int j = t2_start;

            while (i >= 0 && j < size) {
                if (nums[i] + nums[j] == 0) {
                    vector<int> temp = {nums[i], 0 , nums[j]};
                    result.push_back(temp);

                    ++j;
                    --i;
                } else if (nums[i] + nums[j] < 0) {
                    ++j;
                } else {
                    --i;
                }
            }
        }

        // 排除掉0
        vector<int> t1;
        vector<int> t2;

        for (int i = 0; i <= t1_end; ++i) {
            for (int j = i + 1; j <= t1_end; ++j) {
                t1.push_back(nums[i] + nums[j]);
            }
        }

        for (int i = t2_start; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                t2.push_back(nums[i] + nums[j]);
            }
        }

        sort(t1);
        sort(t2);

        return result;
    }
};

int main() {
    Solution solution;

    vector<int> input = {4, -1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = solution.threeSum(input);

    vector<vector<int>>::iterator iter = result.begin();

    for (; iter != result.end(); ++iter) {
        cout << "[" << (*iter)[0] << ", " << (*iter)[1] << ", " << (*iter)[2] << "]" << endl;
    }
    return 0;
}

/*

 [-4, -1, -1, 0, 1, 2]

 */