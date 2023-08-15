/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>
using namespace std;

//暴力法超时
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0; i<cost.size(); i++){
            int leave=gas[i] - cost[i];//记录剩余油量
            int index=(i+1)%cost.size();
            //如果leave>=0 则答案不唯一了
            while(leave>0 && index!=i){
                leave+=gas[index]-cost[index];
                index=(index+1)%cost.size();
            }
            //如果以i为起点跑一圈，剩余油量>=0,返回该起始位置i
            if(leave>=0 && index==i){
                return i;
            }
        }
        return -1;
    }
};

//贪心
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int curnum=0;
        int totalnum=0;
        for(int i=0; i<cost.size(); i++){
            curnum+=gas[i]-cost[i];
            totalnum+=gas[i]-cost[i];
            if(curnum<0){
                start=i+1;
                curnum=0;
            }
        }
        if(totalnum<0) return -1;
        return start;
    }
};
// @lc code=end

