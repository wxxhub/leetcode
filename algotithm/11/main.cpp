#include <iostream>
#include <vector>

using namespace std;

// plan 1
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int size = height.size();
//        int max_area = 0;
//        for (int i = 0; i < size; ++i) {
//            for (int j = i + 1; j < size; ++j) {
//                int area = min(height[i], height[j]) * (j-i);
//                if (area > max_area) {
//                    max_area = area;
//                }
//            }
//        }
//
//        return  max_area;
//    }
//
//    int min(int a, int b) {
//        return a < b ? a : b;
//    }
//};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int max_area = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                int area = min(height[i], height[j]) * (j-i);
                if (area > max_area) {
                    max_area = area;
                }
            }
        }

        return  max_area;
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }
};

int main() {
    Solution solution;
    vector<int> input = {1,8,6,2,5,4,8,3,7};
    cout << solution.maxArea(input) << endl;
    return 0;
}