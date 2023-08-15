/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

//仅用一个for循环
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res=0;
        int index=s.size()-1;
        if(s.size() == 0) return res;
        //先遍历胃口，再遍历饼干
        for(int i=g.size()-1; i>=0; i--){
            if(index>=0 && s[index]>=g[i]){
                res++;
                index--;
            }
        }
        return res;
    }
};


// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(),g.end());
//         sort(s.begin(),s.end());
//         int res=0;
//         int index=s.size()-1;
//         if(s.size() == 0) return res;
//         //先遍历胃口，再遍历饼干
//         for(int i=g.size()-1; i>=0; i--){
//             //int sum=0;
//             for(int j=index; j>=0; j--){
//                 //一个饼干即可满足
//                 //sum+=s[j];
//                 if(s[j] >= g[i]){
//                     res++;
//                     index=j-1;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };


//自解 没有全通过只通过了18/21
// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(),g.end());
//         sort(s.begin(),s.end());
//         int res=0;
//         int index=0;
//         if(s.size() == 0) return res;
//         for(int i=0; i<g.size(); i++){
//             int sum=0;
//             for(int j=index; j<s.size(); j++){
//                 //一个饼干即可满足
//                 sum+=s[j];
//                 if(sum >= g[i]){
//                     res++;
//                     index=j+1;
//                     break;
//                 }
//             }
//         }
//         return res;

//     }
// };
// @lc code=end

