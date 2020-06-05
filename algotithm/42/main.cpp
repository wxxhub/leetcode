#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int end = height.size() - 1;

        if (end < 2) {
            return 0;
        }

        int start = 0;
        int level = 1;

        int sum = 0;

        while (height[start] == 0) {
            start++;
        }

        while (height[end] == 0) {
            end--;
        }

        while (start != end) {
            int cache = 0;
            while (height[start] <= level && start < end) {
                cache += level - height[start];
                start++;
            }
            sum += cache;
            cache = 0;

            while (height[end] <= level && start < end) {
                cache += level - height[end];
                end--;
            }

            sum += cache;

            level++;
        }

        return sum;
    }
};

int main() {
    Solution solution;

    vector<int> input = {2, 0, 2};

    cout << solution.trap(input) << endl;
    return 0;
}
