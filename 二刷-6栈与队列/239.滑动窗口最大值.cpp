/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
// @lc code=start

#include <vector>
#include <deque>
using namespace std;
//自定义单调队列 从大到小
class Solution {
public:
    class Myque{
    public:
        deque<int> dq;
        void push(int value){
            while(!dq.empty() && value > dq.back()){
                dq.pop_back();
            }
            dq.push_back(value);
        }


        //如果当前要弹出的元素等于队首，即弹出队首元素
        void pop(int value){
            if(!dq.empty() && value == dq.front()){
                dq.pop_front();
            }
        }

        int getmax(){
            return dq.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myque que;
        vector<int> res;
        for(int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        res.push_back(que.getmax());
        for(int i = k; i < nums.size(); i++){
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.getmax());
        }
        return res;
    }
};
// @lc code=end

