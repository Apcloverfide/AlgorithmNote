//动态规划的经典题目
//

#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int map[105][105],dp[105][105];
int a[105][105], b[105][105];
int main(){
    int m,k = 0, n ,T;
    cin >> T;
    while(T--){
        cin>> m >> n;
        memset(dp,-999999,sizeof dp);
        memset(a,-999999,sizeof dp);
        memset(b,-999999,sizeof dp);
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++)
                scanf("%d",&map[i][j]);
        }
        dp[0][0] = map[0][0];
        for(int i = 1;i < m;i++){
            dp[i][0] = dp[i-1][0] + map[i][0];
        }
        for(int j = 1;j < n;j++){
            a[0][j] = dp[0][j-1] + map[0][j];
            for(int i = 1;i < m;i++){
                a[i][j] = map[i][j] + max(dp[i][j-1],a[i-1][j]);
            }
            b[m-1][j] = dp[m-1][j-1] + map[m-1][j];
            for(int i = m-2;i >= 0;i--){
                b[i][j] = map[i][j] + max(dp[i][j-1],b[i+1][j]);
            }
            for(int i = 0;i < m;i++){
                dp[i][j] = max(a[i][j],b[i][j]);
            }
        }
        printf("Case #%d:\n",++k);
        // for(int i = 0;i < m;i++){
        //     for(int j = 0;j < n;j++)
        //         cout << dp[i][j] <<" ";
        //     cout << endl;
        // }
        cout << dp[0][n-1] << endl;
    }

    return 0;
}
