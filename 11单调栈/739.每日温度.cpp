/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

//暴力
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         vector<int> res(temperatures.size(),0);
//         for(int i=0; i<temperatures.size(); i++){
//             for(int j=i+1; j<temperatures.size(); j++){
//                 if(temperatures[j] > temperatures[i]){
//                     res[i]=j-i;
//                     break;
//                 }
//                 // if(j == temperatures.size()-1){
//                 //     res[i]=0;
//                 // }
//             }
//         }
//         return res;
//     }
// };

//单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> st;
        st.push(0);
        //本题为递增栈，即从栈头到栈底逐渐增大 往栈中放入元素下标即可
        for(int i=1; i<temperatures.size(); i++){
            if(temperatures[i] < temperatures[st.top()]){
                st.push(i);
            }
            else if(temperatures[i] == temperatures[st.top()]){
                st.push(i);
            }
            else{
                while(!st.empty() && temperatures[i]>temperatures[st.top()] ){
                    res[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
  
    }
};

// @lc code=end

