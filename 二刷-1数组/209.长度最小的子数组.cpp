/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>
using namespace std;

//滑动窗口
/*
    1.窗口起始位置
    2.窗口结束位置
    3.窗口内维护的值
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;
        int sublength = 0; //窗口长度
        int i = 0 ;   //窗口起始位置
        int sum = 0;   //窗口数值之和
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                sum -= nums[i];
                sublength = j - i + 1;
                res = res > sublength ? sublength : res;
                i++;
            }
        }
         
        return  res == INT32_MAX ? 0 : res;
    }
};
// @lc code=end

