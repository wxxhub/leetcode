#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> data_map;
        vector<vector<string>> result;

        int strs_size = strs.size();
        stringstream ssname;

        int nums[26] = {0};

        for (int i = 0; i < strs_size; i++) {
            int str_size = strs[i].size();

            for (int j = 0; j < str_size; j++) {
                nums[strs[i][j] - 'a']++;
            }

            ssname.clear();
            ssname.str("");
            for (int i = 0; i < 26; i++) {
                if (nums[i]) {
                    ssname << char(i + 'a') << nums[i];
                    nums[i] = 0;
                }
            }

            auto iter = data_map.find(ssname.str());
            if (iter == data_map.end()) {
                vector<string> new_strs;
                new_strs.push_back(strs[i]);

                data_map[ssname.str()] = result.size();
                result.push_back(new_strs);
            } else {
                result[iter->second].push_back(strs[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto reulst = solution.groupAnagrams(input);

    return 0;
}
