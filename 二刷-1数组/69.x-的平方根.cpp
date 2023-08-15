/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:


    int mySqrt(int x) {
        int l = 1;
        int r = x;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int tmp = x / mid;
            if(tmp < mid){
                r = mid - 1;
            }else if(tmp > mid){
                l = mid + 1;
            }
            else{
                return mid;
            }
        }
        return r; // r + 1就通过不了  r或者l - 1可以通过 可以拿x = 7举例
    }
};
// @lc code=end

