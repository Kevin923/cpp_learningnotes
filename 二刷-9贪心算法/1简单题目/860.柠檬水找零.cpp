/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
    
        //sort(bills.begin(), bills.end());
        for(auto i: bills) {
            if(i == 5) {
                five++;
            }
            if(i == 10) {
                ten++;
                five -= 1;
            }
            if(i == 20) {
                if(ten > 0) {
                    ten--;
                    five--;
                } else{
                    five -= 3;
                } 
            }
            
            if(five < 0 || ten < 0) {
                return false;
            }
        }


        return true;

    }
};
// @lc code=end

