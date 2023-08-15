/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] == b[0]) {
            //如果身高一样，则第二位小的排在前面
            return a[1] < b[1];
        }
        //从大到小排序
        return a[0] > b[0]; 
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //从大到小进行排序
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> list;
        for(int i = 0; i < people.size(); i++) {
            int pos = people[i][1];
            auto it = list.begin();
            while(pos--) {
                it++;
            }
            list.insert(it, people[i]);
        }

        return vector<vector<int>>(list.begin(), list.end());
    }
};
// @lc code=end

