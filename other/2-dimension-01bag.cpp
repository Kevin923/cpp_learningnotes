#include <iostream>
#include <vector>
using namespace std;

void fun(){
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    int bagweight=4;

    //初始化dp数组
    vector<vector<int>> dp(weight.size(),vector<int>(bagweight+1,0));

    //dp数组赋值
    for(int j=weight[0]; j<=bagweight; j++){
        dp[0][j]=value[0];
    }

    //遍历
    //先遍历物品 再遍历背包
    for(int i=1; i<weight.size(); i++){
        for(int j=0; j<=bagweight; j++){
            if(j<weight[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }
    cout<<dp[weight.size()-1][bagweight];

}

int main(){
    fun();
    getchar();
    return 0;
}