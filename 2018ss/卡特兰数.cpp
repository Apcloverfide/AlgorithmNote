#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int n = 1000005,mod = 1000000007;
ll h[n];
// a的逆元 = qpow(a, mod-2);
ll qpow(ll x,ll y){ //快速求幂
    ll ans = 1;
    while(y){
        if(y&1) ans = ans*x % mod;
        x = x*x%mod;
        y >>= 1;
    }
    return ans;
}
void Catalan(){ // h[n] = h[n-1]*(4*n-2)/(n+1)
    h[0] = 0;h[1] = 1;
    for(int i = 2;i < n;i++){
        h[i] = h[i-1]*(4*i-2)*1LL%mod*qpow(i + 1, mod-2)%mod;  //卡特兰数的递推公式
        //h[i]=((h[i-1]*(4*i-2)%mod)*qpow(i+1,mod-2))%mod;
    }
}
int main(){
    int T, N;
    Catalan();
    cin >> T; //数据组数T(1<=T<=100000)
    for(int i = 1;i <= T;i++){
        scanf("%d",&N);
        printf("Case #%d:\n",i);
        printf("%d\n",h[N]);
    }

    return 0;
}
