/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> res;
    void backtracking(string& s, int index, int pointnum){
        if(pointnum==3){
            if(isvalid(s,index,s.size()-1)){
                res.push_back(s);
            }
            return;
        }

        //单层搜索逻辑
        for(int i=index; i<s.size(); i++){
            if(isvalid(s,index,i)){ //判断[index,i]区间的子串是否合法
                s.insert(s.begin()+i+1, '.'); //在i的后面加一个.
                pointnum++;
                backtracking(s,i+2,pointnum);
                //回溯
                pointnum--;
                s.erase(s.begin()+i+1);
            }
        }
        return;
        
    }

    bool isvalid(string s, int start, int end){
        if(start>end)
            return false;
        //开头字符为0 非法
        if(s[start]=='0' && start!=end){
            return false;
        }
        int num=0;
        for(int i=start; i<end; i++){
            num=num*10+s[i]-'0';
        }
        if(num>255){
            return false;
        }
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if(s.size()<4 || s.size()>12) return res;
        backtracking(s,0,0);
        return res;
    }
};
// @lc code=end

