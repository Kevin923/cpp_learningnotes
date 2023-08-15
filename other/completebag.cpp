#include <iostream>
#include <vector>
using namespace std;

void completebag(){
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    int bagweight=4;

    //一维滚动数组，定义dp及初始化;
    vector<int> dp(bagweight+1,0);

    //遍历 先物品 后背包
    for(int i=0; i<weight.size(); i++){
        //内层不用倒叙了，因为一个物品可以重复添加
        for(int j=weight[i];j<=bagweight; j++){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    
    cout<<dp[bagweight]<<endl; //60 装15 15 30 正好重量为4

}

int main(){

    completebag();
    getchar();
    return 0;
}