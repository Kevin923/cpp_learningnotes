/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return true;
        int i=0;
        int j=num;
        while(j-i>1)
        {
            int m=(i+j)/2;
            if(num/m<m)
            {
                j=m;
            }
            else if(num/m>m)
            {
                i=m;
            }
            else{
                if(num % m==0) return true; //5/2=2 4/2=2
                i=m;
            }
        }
        return false;
    }   
};

// @lc code=end

