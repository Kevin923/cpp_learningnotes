/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_set>
using namespace std;

class Solution {
public:
    int getnum(int num){
        int sum = 0;
        while(num){
            sum += (num % 10) * (num % 10);
            num = num / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> uset;
        while(1){
            int res = getnum(n);
            if(res == 1){
                return true;
            }
            if(uset.find(res) != uset.end()){
                return false;
            }else{
                uset.insert(res);
            }
            n = res;
        }
    }
};
// @lc code=end

