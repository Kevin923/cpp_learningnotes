/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
#include <string>
using namespace std;
//字符匹配应该想到栈得思想，只不过string有现成的接口，可以去模拟栈
// class Solution {
// public:
//     string getstr(string& str){
//         string s;
//         for(int i = 0; i < str.size(); i++){
//             if(str[i] != '#'){
//                 s += str[i];
//             }else if(!s.empty()){
//                 s.pop_back();
//             }
//         }
//         return s;
//     }

//     bool backspaceCompare(string s, string t) {
//         return getstr(s) == getstr(t);
//     }
// };

//从后向前双指针
class Solution {
public:
    //s = "ab#c", t = "ad#c"  true
    //s = "a#c", t = "b"      false
    bool backspaceCompare(string s, string t) {
        int s_skipnum = 0;
        int t_skipnum = 0;
        int i = s.size() - 1;
        int j = t.size() - 1;

        while(1){
            //从后向前消除s的#
            while(i >= 0){
                if(s[i] == '#'){
                    s_skipnum++;
                }else{
                    if(s_skipnum > 0){
                        s_skipnum--;
                    }
                    else{
                        break;
                    }
                }
                i--;
            }

            while(j >= 0){
                if(t[j] == '#'){
                    t_skipnum++;
                }else{
                    if(t_skipnum > 0){
                        t_skipnum--;
                    }
                    else{
                        break;
                    }
                }
                j--;
            }
            // 后半部分#消除完了，接下来比较S[i] != T[j]
            if(i < 0 || j < 0) break; //S 或者T 遍历到头了
            //对应位不相等，即使左一位是#号也没有用
            if(s[i] != t[j]){
                return false;
            }

            i--, j--;
        }
        //说明S和T同时遍历完毕
        if(i == -1 && j == -1) return true;
        return false; // 一个遍历完了 一个没遍历完
    }
};
// @lc code=end

