#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// plan 1
/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        if (nums1.size() == 0){
            return 0;
        } else if (nums1.size() == 1) {
            return  nums1[0];
        }

        int mid = nums1.size() / 2;
        return nums1.size() % 2 == 0 ? (nums1[mid] + nums1[mid - 1]) / 2.0 : 1.0 * nums1[mid];

    }
};
*/


// plan2
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();

        // 当出现空的串
        if (l1 == 0 && l2 == 0) {
            return  0;
        } else if(l1 == 0) {
            if (l2 % 2 == 0) {
                return (nums2[l2/2-1] + nums2[l2/2]) / 2.0;
            } else {
                return  nums2[l2/2];
            }
        } else if(l2 == 0) {
            if (l1 % 2 == 0) {
                return (nums1[l1/2-1] + nums1[l1/2]) / 2.0;
            } else {
                return  nums1[l1/2];
            }
        }

        int sum = l1 + l2;
        int mid = sum / 2;

        // 如果出现一个串比另一个大
        if (nums1[l1-1] <= nums2[0]) {
            nums1.insert(nums1.end(), nums2.begin(), nums2.end());

            if (sum % 2 == 0) {
                return  (nums1[mid-1] + nums1[mid]) / 2.0;
            } else {
                return  nums1[mid];
            }
        } else if (nums2[l2 - 1] <= nums1[0]) {
            nums2.insert(nums2.end(), nums1.begin(), nums1.end());

            if (sum % 2 == 0) {
                return  (nums2[mid-1] + nums2[mid]) / 2.0;
            } else {
                return  nums2[mid];
            }
        }

        // other
        int last_value = 0, value = 0;
        int sit1 = 0, sit2 = 0;
        int siz1 = l1, siz2 = l2;
        for (int i = 0; i < mid; ++i) {
            if (siz1 == 0) {
                last_value = nums2[siz2 + i - mid - 1];
                value = nums2[siz2 + i -mid];
                --siz2;
            } else if (siz2 == 0) {
                last_value = nums1[siz1 + i - mid - 1];
                value = nums1[siz1 + i -mid];
                --siz1;
            } else {
                int s1 = siz1 - 1;
                int s2 = siz2 - 1;
                if (nums1[s1] >= nums2[s2]) {
                    last_value = nums1[s1];

                    if (s1 > 0) {
                        value = nums1[s1 - 1] > nums2[s2] ? nums1[s1 - 1] : nums2[s2];
                    } else {
                        value = nums2[s2];
                    }
                    --siz1;
                } else {
                    last_value = nums2[s2];
                    if (s1 > 0) {
                        value = nums2[s2 - 1] > nums1[s1] ? nums2[s2 - 1] : nums1[s1];
                    } else {
                        value = nums1[s1];
                    }
                    --siz2;
                }
            }
        }

        if (sum % 2 == 0) {
            return  (last_value + value) / 2.0;
        } else {
            return  value;
        }
    }
};

int main() {
    Solution solution;

//    vector<int> nums1 = {1, 2, 5};
//    vector<int> nums2 = {3, 4};

//    vector<int> nums1 = {0, 0};
//    vector<int> nums2 = {0, 0};

//    vector<int> nums1 = {3, 4};
//    vector<int> nums2;

//    vector<int> nums1 = {2};
//    vector<int> nums2 = {1, 3, 4};

//    vector<int> nums1 = {1,2,3,4,6};
//    vector<int> nums2 = {5};

//    vector<int> nums1 = {1,2};
//    vector<int> nums2 = {-1, 3};

    vector<int> nums1 = {1, 2, 4};
    vector<int> nums2 = {3};

    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}