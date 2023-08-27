/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
//剑指offer也有
/*
1 2 3 4
24 12 8 6
*/
    //空间O(1)的做法 输出数组不算额外空间
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        //使用变量代替right数组 res当作left数组使用
        for(int i = 1; i < nums.size(); i++) {
            res[i] = nums[i - 1] * res[i - 1];
        }

        int right = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            res[i] = res[i] * right;
            right *= nums[i];
        }

        return res;
    }
    //时间 O(n) 空间 O(n)
    // vector<int> constructArr(vector<int>& a) {
    //     if(a.size() == 0) return {};
    //     vector<int> res(a.size(), 0);
    //     vector<int> left(a.size(), 1);
    //     vector<int> right(a.size(), 1);
    //     for(int i = 1; i < a.size(); i++) {
    //         left[i] = left[i - 1] * a[i - 1]; 
    //     }

    //     for(int i = a.size() - 2; i >= 0; i--) {
    //         right[i] = right[i + 1] * a[i + 1];
    //     }

    //     for(int i = 0; i < a.size(); i++) {
    //         res[i] = left[i] * right[i];
    //     }
    //     return res;
    // }
};
// @lc code=end

