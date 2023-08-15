/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution {  //单调队列
private:
    class Myqueue{
    public:
        deque<int> dq;
        
        void pop(int value){
            if(!dq.empty() && value==dq.front()){
                dq.pop_front();
            }
        }
        void push(int value){
            while(!dq.empty() && dq.back()<value){
                dq.pop_back();
            }
            dq.push_back(value);
        }

        int getMaxvalue(){
            return dq.front();
        }
    };

public:
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> res;
    //     for(int i=0;i<nums.size();i++){
    //         if(i+k-1< nums.size()){
    //             int max=-100001;
    //             for(int j=i;j<=i+k-1;j++){
    //                 max=nums[j]>max?nums[j]:max;
    //             }
    //             res.push_back(max);
    //         }
    //     }

    //     return res;
    // }

    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        Myqueue que;
        vector<int> res;
        for(int i=0;i<k;i++){
            que.push(nums[i]);
        }
        res.push_back(que.getMaxvalue());
        for(int i=k;i<nums.size();i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            res.push_back(que.getMaxvalue());
        }

        return res;
    }



};
// @lc code=end

