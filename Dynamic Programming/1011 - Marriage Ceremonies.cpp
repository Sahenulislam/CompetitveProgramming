#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const ll mxn=16;
ll a[mxn+10][mxn+10];
ll dp[mxn+2][(1<<17)+10];
ll n;
ll call(ll i,ll mask)
{
    if(i>=n)return 0;

    if(dp[i][mask]!=-1)return dp[i][mask];
    ll mx=-1;
    for(ll j=0; j<n; j++)
    {
        ll x=1<<j;
        if(!(x&mask))
        {
            mx=max(mx,a[i][j]+call(i+1,mask|x));
        }
    }
    return dp[i][mask]=mx;
}
int main()
{
    fast
    ll t,tt=1;
    memset(dp,-1,sizeof(dp));
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=0; i<n; i++)
            for(ll j=0; j<n; j++)
                cin>>a[i][j];
        cout<<"Case "<<tt++<<": "<<call(0,0)<<endl;
        memset(dp,-1,sizeof(dp));
    }
    return 0;
}
