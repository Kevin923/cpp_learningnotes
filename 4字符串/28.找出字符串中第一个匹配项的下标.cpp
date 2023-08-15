/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    //KMP
    //前缀：指不包含最后一个字符的所有以第一个字符开头的连续子串。
    //后缀：指不包含第一个字符的所有以最后一个字符结尾的连续子串。
    //next数组即前缀表 记录最长相等前后缀的长度
    //前缀表的作用：前缀表是用来回退的，它记录了模式串与主串(文本串)不匹配的时候，模式串应该从哪里开始重新匹配
    // 文本串：aabaabaafa
    // 模式串：aabaaf

    //构建next数组
    //1.初始化 2.前后缀不相等的情况 3.前后缀相等的情况
    void getNext(int *next, string &s){
        int j=0;   // j前缀末尾  i后缀末尾  j也表示i（包括i）之前的最长相等前后缀的长度
        next[0]=0;
        for(int i=1;i<s.size();i++){
            //前后缀不等
            while(j>0 && s[i] != s[j]){ //j-1 >= 0  
                j=next[j-1];
            }
            //前后缀相等
            if(s[i]==s[j]){
                j++;
            }
            next[i]=j;
        }
    }

    int strStr(string haystack, string needle) { //KMP haystack文本串 needle模式串
        if(needle.size()==0) return 0;
        int next[needle.size()];
        getNext(next,needle);
        int j=0; //j从模式串出发
        for(int i=0;i<haystack.size();i++){  //i从文本串出发
            while( j>0 && haystack[i]!=needle[j]){  //j-1>0
                j=next[j-1];
            }
            if(haystack[i]==needle[j]){
                j++;
            }
            if(j==needle.size()){
                return (i-needle.size()+1);
            }
            
        }
    
        return -1;
    }

};
// @lc code=end

