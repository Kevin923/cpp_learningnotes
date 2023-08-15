/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

//暴力双层for循环 超时
class Solution {
public:
    //单调栈
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> res(len, 0);
        stack<int> st;
        st.push(0);
        //求右边第一个大于自己的元素 栈头到栈底 应该递增
        for(int i = 1; i < len; i++) {
            //栈里存下标即可
            if(temperatures[i] <= temperatures[st.top()]) {
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }

    // vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     int len = temperatures.size();
    //     vector<int> res(len, 0);
    //     for(int i = 0; i < len; i++) {
    //         for(int j = i + 1; j < len; j++) {
    //             if(temperatures[j] > temperatures[i]) {
    //                 res[i] = j - i;
    //                 break;
    //             }
    //         }
    //     }
    //     return res;
    // }
};
// @lc code=end

