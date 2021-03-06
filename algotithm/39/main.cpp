#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> cache;
        sort(candidates.begin(), candidates.end());
        process(0, target, cache, result, candidates);
        return result;
    }

    void process(int start , int value, vector<int> &cache, vector<vector<int>> &result, vector<int>& candidates) {
        int size = candidates.size();
        for (; start < size; start++) {
            if (candidates[start] < value) {
                cache.push_back(candidates[start]);
                process(start, value - candidates[start], cache, result, candidates);
                cache.pop_back();
            } else if (candidates[start] == value) {
                cache.push_back(candidates[start]);
                result.push_back(cache);
                cache.pop_back();
                return;
            } else {
                return;
            }
        }
    }
};

int main() {
    vector<int> candidates = {2, 3, 5};

    Solution solution;

    solution.combinationSum(candidates, 8);
    return 0;
}
