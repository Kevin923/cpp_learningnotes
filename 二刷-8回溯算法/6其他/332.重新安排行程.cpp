/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start

#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    //unordered_map<出发地点, map<到达地点, 票数>> 
    unordered_map<string, map<string, int>> target;

    bool backtracking(int ticketnum, vector<string>& res) {
        if(res.size() == ticketnum + 1) {
            return true;
        }

        for(auto& index : target[res[res.size() - 1]]) {
            if(index.second > 0) {
                res.push_back(index.first);
                index.second--;
                if(backtracking(ticketnum, res)) {
                    return true;
                }
                res.pop_back();
                index.second++;
            }
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        for(auto& vec : tickets) {
            target[vec[0]][vec[1]]++;
        }
        res.push_back("JFK");
        backtracking(tickets.size(), res);
        return res;
    }
};
// @lc code=end

