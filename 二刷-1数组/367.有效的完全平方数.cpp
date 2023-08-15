/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int tmp = num / mid;
            if(tmp < mid){
                r = mid - 1;
            }else if(tmp > mid){
                l = mid + 1;
            }
            else{
                // 5/2 4/2
                if(num % mid == 0){
                    return true;
                }
                return false;
            }
        }
        return false;
    }
};
// @lc code=end

