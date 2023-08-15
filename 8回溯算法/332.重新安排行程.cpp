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
private:
    //unordered<出发地点，map<到达地点，票的张数>> targets
    unordered_map<string,map<string,int>> targets;
    //有一条路径即可返回，即地方全到了，res中的数=票的数+1；
    bool backtracking(int ticketnum, vector<string>& res){
        if(res.size() == ticketnum+1){
            return true;
        }
        for(pair<const string, int>& target: targets[res[res.size()-1]]){
            if(target.second > 0){
                res.push_back(target.first);
                target.second--;
                if(backtracking(ticketnum, res)){
                    return true;
                }
                target.second++;
                res.pop_back();
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        vector<string> res;
        for(const vector<string>& vec: tickets){
            //targets[vec[0]]代表哈希表的key targets[vec[0]][vec[1]]++
            //代表map中的key对应的value++;
            targets[vec[0]][vec[1]]++; //记录映射关系
        }
        res.push_back("JFK");
        backtracking(tickets.size(), res);
        return res;
    }
};
// @lc code=end

