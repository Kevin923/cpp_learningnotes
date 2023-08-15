/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //sort(bills.begin(), bills.end());
        int num5=0;
        int num10=0;
        int num20=0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                num5++;
            }
            if(bills[i] == 10){
                if(num5<=0) return false;
                num10++;
                num5--;
            }
            if(bills[i] == 20){
                if(num10>0 && num5>0){
                    num20++;
                    num10--;
                    num5--;
                }
                else if(num10==0 && num5>0){
                    num5-=3;
                    if(num5<0){
                        return false;
                    }
                    num20++;
                }
                else{
                    return false;
                }

            }
        }
        return true;
    }
};
// @lc code=end

