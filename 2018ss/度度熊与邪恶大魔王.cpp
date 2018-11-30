#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define max_n 100010
#define INF 0x3f3f3f3f
using  namespace std;
typedef long long LL;
LL dp[1005][12];
LL a[max_n], b[max_n], k[max_n], p[max_n];
 
int main() {
	LL p1, p2, n, m;
	while(scanf("%lld %lld", &n, &m) != EOF) {
		LL maxn1 = 0, maxn2 = 0;
		for(LL i = 0; i < n; i++) {
			scanf("%lld %lld", &a[i], &b[i]);
			maxn1 = max(maxn1, b[i]);
		}
		for(LL i = 0; i < m; i++) {
			scanf("%lld %lld", &k[i], &p[i]);
			maxn2 = max(maxn2, p[i]);
		}
		if(maxn2 <= maxn1) {   //特判一下，最大攻击值不大于防御值 
			printf("-1\n");
			continue;
		}
		memset(dp, INF, sizeof(dp));
		for(LL i = 0; i <= 10; i++) {
			for(LL v = 1; v < 1005; v++) {  //枚举血量 
				for(LL j = 0; j < m; j++) { //枚举攻击值，处理成完全背包 
					LL res = p[j] - i;
					if(res <= 0) continue;
					if(res >= v) dp[v][i] = min(dp[v][i], k[j]); //分情况 
					else dp[v][i] = min(dp[v][i], dp[v - res][i] + k[j]);
				}
			}
		}
		LL ans = 0;
		for(LL i = 0; i < n; i++) {
			ans += dp[a[i]][b[i]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
--------------------- 
作者：HPU王小二 
来源：CSDN 
原文：https://blog.csdn.net/qq_36368339/article/details/76854158 
版权声明：本文为博主原创文章，转载请附上博文链接！
