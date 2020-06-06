#include <iostream>
#include <vector>
#include <list>

using namespace std;

// list占用更多的内存空间
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size() - 1;
        }

        vector<int> distance_cache = {1};
        int nums_end = nums.size() - 1;
        for (int i = 2; i <= nums_end; i++) {
            int current_distance = nums[nums_end - i];

            int end_value = *distance_cache.rbegin();
            if (current_distance <= end_value) {
                distance_cache.push_back(1);
            } else {
                while (end_value < current_distance) {
                    current_distance -= end_value;

                    distance_cache.pop_back();
                    if (distance_cache.empty()) {
                        break;
                    }

                    end_value = *distance_cache.rbegin();
                }

                distance_cache.push_back(nums[nums_end - i] - current_distance + 1);
            }
        }

        return distance_cache.size();
    }
};

// list占用更多的内存空间
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        if (nums.size() <= 2) {
//            return nums.size() - 1;
//        }
//
//        list<int> distance_cache = {1};
//        int nums_end = nums.size() - 1;
//        for (int i = 2; i <= nums_end; i++) {
//            int current_distance = nums[nums_end - i];
//
//            int end_value = *distance_cache.rbegin();
//            if (current_distance <= end_value) {
//                distance_cache.push_back(1);
//            } else {
//                while (end_value < current_distance) {
//                    current_distance -= end_value;
//
//                    distance_cache.pop_back();
//                    if (distance_cache.empty()) {
//                        break;
//                    }
//
//                    end_value = *distance_cache.rbegin();
//                }
//
//                distance_cache.push_back(nums[nums_end - i] - current_distance + 1);
//            }
//        }
//
//        return distance_cache.size();
//    }
//};

int main() {
    Solution solution;

    vector<int> input = {1, 2, 3, 4, 5};

    cout << solution.jump(input) << endl;
    return 0;
}
