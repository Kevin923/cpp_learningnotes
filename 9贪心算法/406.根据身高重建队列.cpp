/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

//注意使用list<vector<int>> 时间效率要比使用二维vector高的多
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0] == b[0]){
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> res; //list 底层实现是链表
        for(int i=0; i<people.size(); i++){
            int position=people[i][1];
            list<vector<int>>::iterator it=res.begin();
            while(position--){
                it++;
            }
            res.insert(it,people[i]);
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};
// @lc code=end

