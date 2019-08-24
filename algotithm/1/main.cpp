#include <iostream>
#include <vector>

using namespace std;

// 1
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        Label label;
        label.sit = 0;
        label.value = nums[0];
        label_list_.push_back(label);
        for (int i = 1; i < nums.size(); ++i){
            bool same = false;
            for (int j = 0; j < label_list_.size(); ++j){
                if (label_list_[j].value + nums[i] == target){
                    result.push_back(label_list_[j].sit);
                    result.push_back(i);
                    return  result;
                }

                if (label_list_[j].value == nums[i]){
                    same = true;
                }
            }

            if (!same){
                Label new_label;
                new_label.sit = i;
                new_label.value = nums[i];
                label_list_.push_back(new_label);
            }
        }

        return result;
    }

private:
    struct Label{
        int sit;
        int value;
    };

    vector<Label> label_list_;
};

// 2
/*
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for (int i = 0; i < 1000; ++i){
            label[i] = -1;
        }

        for (int i = 0; i < nums.size(); ++i){
            if (label[nums[i] + 500] == -1){
                label[nums[i] + 500] = i;
            }

            if (label[nums[i] + 500] != -1 && label[target - nums[i] + 500] != -1) {
                if (label[nums[i] + 500] <= label[target - nums[i] + 500]) {
                    result.push_back(label[nums[i] + 500]);
                    result.push_back(label[target - nums[i] + 500]);
                } else {
                    result.push_back(label[target - nums[i] + 500]);
                    result.push_back(label[nums[i] + 500]);
                }

                return  result;
            }
        }

        return result;
    }

private:
    int label[1000] = {0};
};
 */

int main() {

    Solution solution;
    vector<int> input = {2, 9, 10, 7, 11, 3, 15};

    vector<int> result = solution.twoSum(input, 13);

    if (result.size() == 2){
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "size: " << result.size() << endl;
    }
    return 0;
}