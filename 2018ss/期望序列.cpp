#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
ll n;
ll L[maxn],R[maxn];
ll qpow(ll a,ll b)
{
    ll ans=1LL;
    a%=mod;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
ll js(ll l,ll r)
{
    if(r<l)return 0;
    return (r+l)*(r-l+1)/2;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        ll li=0,ri=0;
        ll inv=1LL;
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld%lld",&L[i],&R[i]);
            ri=max(R[i],ri);
            li=max(L[i],li);
            inv=inv*(R[i]-L[i]+1)%mod;
        }
        ll ans=0;
        for(ll i=li;i<=ri;i++)
        {
            ll sum1=1LL,sum2=1LL;
            for(ll j=1;j<=n;j++)
            {
                sum1=sum1*js(i+1-min(R[j],i),i+1-L[j])%mod;
            }
            for(ll j=1;j<=n;j++)
            {
                sum2=sum2*js(i+1-min(R[j],i-1),i+1-L[j])%mod;
            }
            ans=(ans+(sum1-sum2+mod)%mod)%mod;
        }
        ans=ans*qpow(inv,mod-2)%mod;
        printf("%lld\n",ans);
 
    }
    return 0;
}
