#include <iostream>
#include <vector>
using namespace std;

void fun(){
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    int bagweight=4;

    //初始化dp数组
    vector<int> dp(bagweight+1,0);

    //遍历dp数组
    //先物品后背包 从后往前倒叙遍历
    for(int i=0; i<weight.size(); i++){
        for(int j=bagweight; j>=weight[i]; j--){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }

    cout<<dp[bagweight]<<endl;
}

int main(){
    fun();
    getchar();
    return 0;
}