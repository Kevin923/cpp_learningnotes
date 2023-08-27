/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
#include <vector>
using namespace std;

//方法1 辅助空间res结果数组
// class Solution {
// public:
//     vector<int> sortArrayByParityII(vector<int>& nums) {
//         vector<int> res(nums.size());
//         int ouindex = 0;
//         int jiindex = 1;
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] % 2 == 0){
//                 res[ouindex] = nums[i];
//                 ouindex += 2;
//             }else{
//                 res[jiindex] = nums[i];
//                 jiindex += 2;
//             }
//         }
//         return res;
//     }
// };

//在原数组上遍历
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int jiindex = 1;
        for(int i = 0; i < nums.size(); i += 2){
            if(nums[i] % 2 == 1){//在偶数位遇到了奇数
                //在奇数位找个偶数
                while(nums[jiindex] % 2 != 0){
                    jiindex += 2;
                }
                swap(nums[i], nums[jiindex]);
            }
        }
        return nums;
    }
};
// @lc code=end

