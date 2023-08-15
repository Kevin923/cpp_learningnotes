#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//替换空格
class Solution {
public:
    string replaceSpace(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') count++;
        }
        int old_s=s.size();
        s.resize(s.size()+count*2);
        int new_s=s.size();
        for(int i=new_s-1,j=old_s-1; j < i; i--,j-- ){
            if(s[j]!=' '){
                s[i]=s[j];
            }else{
                s[i]='0';
                s[i-1]='2';
                s[i-2]='%';
                i=i-2;   
            }
        }
        return s;
    }
};


//p76
int main()
{
    string A="ADOBECODEBANC";
    string B="ABC";
    unordered_map<char,int> hs;
    unordered_map<char,int> ht;
    for(auto item:B){
        ht[item]++;
    }
    string res;
    int ans=0;
    for(int i=0,j=0;i<A.size();i++){
        hs[A[i]]++;
        if(hs[A[i]]<=ht[A[i]]){
            ans++;
        }
        while(j<i && hs[A[j]]>ht[A[j]]){
            hs[A[j]]--;
            j++;
        }
        if(ans==B.size())
        {
            if(res.empty() || res.size()>i-j+1)
                res=A.substr(j,i-j+1);
        }
    }
    cout<<res;


    getchar();
    return 0;
}