/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while(i < name.size() && j < typed.size()){
            if(name[i] == typed[j]){
                i++;
                j++;
            }
            else{
                //第一位就不同
                if(j == 0) return false;

                //j有重复，往后遍历, 同时防止j越界
                while(j < typed.size() && typed[j] == typed[j - 1]){
                    j++;
                }
                if(typed[j] == name[i]){
                    i++;
                    j++;
                }else{
                    return false;
                }
            }
        } 
        //name长度 大于 typed长度 例如 name:"pyplrzzzzdsfa" type:"ppyypllr"
        if(i < name.size()){
            return false;
        }

        //typed长度 大于name长度 例如 name:"alex" type:"alexxrrrrssda"
        while(j < typed.size()){
            if(typed[j] == typed[j - 1]){
                j++;
            }
            else{
                return false;
            }
        }
        
        return true;

    }
};
// @lc code=end

