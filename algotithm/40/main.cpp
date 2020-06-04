#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> cache;
        sort(candidates.begin(), candidates.end());
        process(0, target, cache, result, candidates);
        return result;
    }

    void process(int start , int value, vector<int> &cache, vector<vector<int>> &result, vector<int>& candidates) {
        int size = candidates.size();
        int last_value = 0;
        for (; start < size; start++) {
            if (last_value == candidates[start]) {
                continue;
            }
            if (candidates[start] < value) {
                cache.push_back(candidates[start]);
                process(start + 1, value - candidates[start], cache, result, candidates);
                cache.pop_back();
            } else if (candidates[start] == value) {
                cache.push_back(candidates[start]);
                result.push_back(cache);
                cache.pop_back();
                return;
            } else {
                return;
            }

            last_value = candidates[start];
        }
    }
};

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};

    Solution solution;

    solution.combinationSum2(candidates, 8);
    return 0;
}