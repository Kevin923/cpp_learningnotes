/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
//暴力 双指针 单调栈
// class Solution {
// public:
// //双指针
//     int trap(vector<int>& height) {
//         int len=height.size();
//         vector<int> maxleft(len,0);
//         vector<int> maxright(len,0);

//         //记录当前位置左边最高的柱子
//         maxleft[0]=height[0];
//         for(int i=1; i<len; i++){
//             maxleft[i]=max(height[i],maxleft[i-1]);
//         }

//         //记录当前位置右边最高的柱子
//         maxright[len-1]=height[len-1];
//         for(int i=len-2; i>=0; i--){
//             maxright[i]=max(height[i],maxright[i+1]);
//         }

//         int sum=0;
//         for(int i=0; i<len; i++){
//             int count=min(maxright[i], maxleft[i])-height[i];
//             //cout<<count;
//             if(count>0){
//                 sum+=count;
//             }
//         }
//         return sum;
//     }
// };

class Solution {
public:
//单调栈
    int trap(vector<int>& height) {
        int len=height.size();
        stack<int> s;
        //栈中放元素下标，从栈顶到栈底元素逐渐增大
        s.push(0);
        int sum=0;
        for(int i=1; i<len; i++){
            if(height[i] < height[s.top()]){
                s.push(i);
            }
            else if(height[i] == height[s.top()]){
                s.pop();
                s.push(i);
            }
            else{
                while(!s.empty() && height[i] > height[s.top()]){
                    int mid=s.top();
                    s.pop();
                    //注意
                    if(!s.empty()){
                        int h=min(height[s.top()],height[i])-height[mid];
                        int w=i-s.top()-1;
                        sum+=h*w;
                    }
                 
                }
                s.push(i);
            }
        }
        return sum;
    }
};


// @lc code=end

