/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
//二分法第二种
/*
    为什么是r - l > 1 而不是r - l >= 1?
    1.最后就剩余两个数 ，平均值
    永远等于左边，这样取等号就会陷入死循环，跳不出来
    2.因为 r-l = 1 的时候，已经得到
    了正确的结果但是还是没有跳出循环
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x==1)
            return 1;
        int left=0;
        int right=x;
        while(right-left>1)
        {
            int middle=(left+right)/2;
            if(x/middle<middle)
                right=middle;
            else
                left=middle;
        }
        return left;
    }
};



// @lc code=end

