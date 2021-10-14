#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1000003;

ll big_mod(ll a,ll b)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll tm=big_mod(a,b/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return ((a%mod)*(big_mod(a,b-1)%mod))%mod;
}

const ll mx=1e6+1;
ll fac[mx];
void factorial()
{
    fac[0]=1;
    for(ll i=1; i<=1e6; i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
}

ll ncr(ll n,ll r)
{
    return (fac[n]*((big_mod(fac[n-r],mod-2)*big_mod(fac[r],mod-2))%mod))%mod;
}

int main()
{
    factorial();
    ll n,r,t,tt=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        cout<<"Case "<<tt++<<": "<<ncr(n,r)<<endl;
    }
    return 0;
}


