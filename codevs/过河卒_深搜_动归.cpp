//问题链接：http://codevs.cn/problem/1010/
//两种解法
//1,动态规划解法
#include<iostream>
using namespace std;
int n,m;
int x,y;
int dp[20][20];
int f[20][20];
void init(){
    if(x>=2) {
        if(y-1>=0)
            f[x - 2][y-1] = 1;
        if(y+1<=m)
            f[x - 2][y+1] = 1;
    }
    if(x+2 <= n){
        if(y-1>=0)
            f[x + 2][y-1] = 1;
        if(y+1<=m)
            f[x + 2][y+1] = 1;
    }
    if(y - 2 >= 0){
        if(x - 1 >= 0)
            f[x - 1][y-2] = 1;
        if(x + 1 <= n)
            f[x + 1][y-2] = 1;
    }
    if(y + 2 <= m) {
        if (x - 1 >= 0)
            f[x - 1][y + 2] = 1;
        if (x + 1 <= n)
            f[x + 1][y + 2] = 1;
    }
    f[x][y] = 1;
    dp[0][0] =1;
}
int main(){
    cin >> n >> m;
    cin >> x >> y;
    //动态规划
    //定义状态： dp[i][j] 就是到i,j的路径条数==>最优子结构
    //状态转移： dp[i][j] = dp[i][j-1] + dp[i-1][j] ()
    //                   = 0  i,j 在马的控制范围内 
    init();
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++)
            cout << f[i][j] <<" ";
        cout<< endl;
    }
    for(int i = 0;i <= m;i++){
        if(f[0][i] == 1)
            break;
        dp[0][i] = 1;
    }for(int i = 0;i <= n;i++){
        if(f[i][0] == 1)
            break;
        dp[i][0] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(f[i][j] == 1){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    cout << "################"<<endl;
    
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++)
            cout <<dp[i][j] <<" ";
        cout << endl;
    }
    cout << dp[n][m] << endl;
    return 0;
}


//解法二：深搜
#include <cstring>
#include <iostream>
using namespace std;
int n, m;   //右下角的坐标
int x, y;   //马的坐标
int ans;
int f[20][20];
void dfs(int a,int b){
    //递归终点
    if(f[a][b] == 1)
        return;
    if(a == n && b==m){
        ans++;
        return;
    }
    //移动，只能向下或者向右移动
    if(a <= n){
        a++;
        dfs(a,b);
        a--;
    }
    if(b <= m){
        b++;
        dfs(a,b);
        b--;
    }

}
void init(){
    if(x>=2) {
        if(y-1>=0)
            f[x - 2][y-1] = 1;
        if(y+1<=m)
            f[x - 2][y+1] = 1;
    }
    if(x+2 <= n){
        if(y-1>=0)
            f[x + 2][y-1] = 1;
        if(y+1<=m)
            f[x + 2][y+1] = 1;
    }
    if(y - 2 >= 0){
        if(x - 1 >= 0)
            f[x - 1][y-2] = 1;
        if(x + 1 <= n)
            f[x + 1][y-2] = 1;
    }
    if(y + 2 <= m) {
        if (x - 1 >= 0)
            f[x - 1][y + 2] = 1;
        if (x + 1 <= n)
            f[x + 1][y + 2] = 1;
    }
    f[x][y] = 1;
}
int main(){
    //memset(f,2, sizeof(f));
    cin >> n >> m;
    cin >> x >> y;
    init();
//    for(int i = 0;i < n;i++){
//        for(int j = 0;j < m;j++){
//            cout << f[i][j] << " ";
//        }
//        cout << endl;
//    }
    //swap(m,n);
    dfs(0,0);
    cout << ans <<endl;
}  
