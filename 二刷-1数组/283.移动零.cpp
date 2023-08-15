/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
using namespace std;

//本题于27移除元素同理
class Solution {
public:
//双指针数组原地操作,slowindex后的元素就是需要赋值为0的元素
    void moveZeroes(vector<int>& nums) {
        int slowindex = 0;
        for(int fastindex = 0; fastindex < nums.size(); fastindex++){
           if(nums[fastindex] != 0){
                nums[slowindex] = nums[fastindex];
                slowindex++;
           } 
        }
        for(int i = slowindex; i < nums.size(); i++){
            nums[i] = 0;
        }

    }
};
// @lc code=end

