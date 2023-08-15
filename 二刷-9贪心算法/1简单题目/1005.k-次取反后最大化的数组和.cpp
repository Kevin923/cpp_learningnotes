/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        int res = 0;
        if(k % 2 == 1) {
            nums[nums.size() -1] *= -1;
        }
        for(auto i: nums) {
            res += i;
        }
        return res;
    }
};
// @lc code=end

