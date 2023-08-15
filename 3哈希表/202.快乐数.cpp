/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution { //难 注意按位数求和方法
public:
    int getsum(int n){
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> ss; 
        while(1){
            int res=getsum(n);
            if(res==1)
                return true;
            if(ss.find(res)!=ss.end()){
                return false;
            }else{
                ss.insert(res);
            }
            n=res;
        }
    }
};
// @lc code=end

