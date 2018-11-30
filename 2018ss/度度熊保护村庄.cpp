#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define inf 1044266558
typedef struct Point{
    int x, y;
    Point operator -(const Point &b) const {
        Point c;
        c.x = x - b.x; c.y = y - b.y;
        return c;
    }

    double operator *(const Point &b) const {   //重载乘法为叉乘
        return x*b.y-y*b.x;                     //判断点是否在有向线的同一侧
    }
};
Point h[505],s[505];
int n , m ,ans , road[505][505];
int main(){
    int i, j , k, flag;
    while (scanf("%d",&n) != EOF){
        memset(road,inf, sizeof(road))
        for(int i = 1;i <= n;i++)
            scanf("%d%d",&h[i].x, &h[i].y);
        scanf("%d",&m);
        for(int i = 1;i <= m;i++)
            scanf("%d%d",&s[i].x,&s[i].y);
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= m;j++){
                flag = 1;
                for(k = 1;k <= n;k++){  //穷举每一个
                    //行列式叉乘判断所有的点是否在同一侧，具体可以统一为右侧
                    //或者是否在这两点之间的连线上
                    //建立每一个边长都为1的有向图
                    //更新road[i][j] = 1
                }
            }
        }
        for(int k = 1;k <= m;k++){      //floyd
            for(int i = 1;i <= m;i++){
                if(road[i][k] == inf)
                    continue;
                for(int j = 1;j <= m;j++){
                    if(road[k][j] == inf) continue;
                    road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
                }
            }
        }
        ans = inf;
        for(int i = 1;i <= m;i++){
            ans = min(ans,road[i][i]);
        }
        if(ans > m)
            cout << "ToT" << endl;
        else cout << m - ans;
    }
}
