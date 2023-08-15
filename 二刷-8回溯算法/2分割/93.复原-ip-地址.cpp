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
public:
    vector<string> res;
    //pointnum 句点个数
    void back(string &s, int index, int pointnum){
        if(pointnum == 3){
            //检查第四个字符串是否符合要求
            if(isvalid(s, index, s.size() - 1)){
                res.push_back(s);
                return;
            }
        }

        //单层逻辑
        for(int i = index; i < s.size(); i++) {
            if(isvalid(s, index, i)){
                pointnum++;
                s.insert(s.begin() + i + 1, '.');
                back(s, i + 2, pointnum);
                s.erase(s.begin() + i + 1);
                pointnum--;
            }
            else{
                //不符合要求直接跳出本层循环
                break;
            }
        }
        return;
    }

    bool isvalid(string& s, int start, int end) {
        /*
            1.不能含前导0
            2.每位数都在0-9
            3.不能大于255
        */
        if(start > end){
            return false;
        }

        if(s[start] == '0' && start != end){
            return false;
        }
        int num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] < '0' || s[i] > '9'){
                return false;
            }

            num = num * 10 + s[i] - '0';
        }
        if(num > 255) {
            return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if(s.size() < 4 || s.size() > 12) {
            return res;
        }
        back(s, 0, 0);
        return res;
    }
};
// @lc code=end

