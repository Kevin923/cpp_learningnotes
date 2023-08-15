/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

//双指针 或单调栈
class Solution {
public:
//单调栈 本题为递减栈，即从栈头到栈底元素应逐渐减小
    int largestRectangleArea(vector<int>& heights) {
        
        int res=0;
        stack<int> s;
        heights.insert(heights.begin(),0);
        heights.push_back(0);
        s.push(0);
        int len=heights.size();
        //vector前后分别加入1个0，是heights有可能出现单调递增
        //或者递减的情况
    
        for(int i=1; i<len; i++){
            if(heights[i] > heights[s.top()]){
                s.push(i);
            }
            else if(heights[i] == heights[s.top()]){
                s.pop();
                s.push(i);
            }
            else{
           
                while(!s.empty() && heights[i]<heights[s.top()]){
                    int mid=s.top();
                    s.pop(); 
                    if(!s.empty()){
                        int w=i-s.top()-1;
                        int h=heights[mid];
                        res=max(res,w*h);
                    }
                }
                s.push(i);
            }
        }
        return res;

    }
};
// @lc code=end

