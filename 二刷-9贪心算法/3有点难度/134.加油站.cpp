/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cursum = 0;
        int sum = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++) {
            cursum += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            //当前油量断油了 应该从下一个位置出发，并重新统计cursum
            if(cursum < 0) {
                start = i + 1;
                cursum = 0;
            }
        }
        // sum += gas[i] - cost[i]小于0 说明油量不够 不能走一圈
        if(sum < 0) {
            return -1;
        }
        return start;
    }
};
// @lc code=end

