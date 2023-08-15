/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> sweet(ratings.size(),1);
        //从前向后，确定右孩子
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i]>ratings[i-1]){
                sweet[i]=sweet[i-1]+1;
            }
        }

        //从后向前，确定左孩子
        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                sweet[i]=max(sweet[i],sweet[i+1]+1);
            }
        }
        int res=0;
        for(int i:sweet){
            res+=i;
        }
        return res;
    }
};
// @lc code=end

