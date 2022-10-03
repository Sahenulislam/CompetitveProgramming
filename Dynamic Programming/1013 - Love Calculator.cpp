#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printv(x) for(ll i=0;i<x.size();i++){if(i+1==x.size())cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define printa(x,n) for(ll i=0;i<n;i++){if(i+1==n)cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
ll dp[40][40];
string s1,s2;
ll dp2[40][40][80];
ll call(ll i,ll j)
{
    if(i==s1.size())
    {
        return s2.size()-j;
    }
    if(j==s2.size())
    {
        return s1.size()-i;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i]==s2[j])
    {
        return dp[i][j]=1+call(i+1,j+1);
    }
    if(s1[i]!=s2[j])
    {
        ll a=min(1+call(i+1,j),1+call(i,j+1));
        return dp[i][j]=a;
    }
}

ll call2(ll i,ll j, ll x)
{
    if(i==s1.size())
    {
        x-=(s2.size()-j);
        if(x==0)return 1;
        else return 0;
    }

    if(j==s2.size())
    {
        x-=(s1.size()-i);
        if(x==0)return 1;
        else return 0;
    }

    if(dp2[i][j][x]!=-1)return dp2[i][j][x];
    if(s1[i]==s2[j])
        return dp2[i][j][x]=call2(i+1,j+1,x-1);
    else
        return dp2[i][j][x]=call2(i+1,j,x-1)+call2(i,j+1,x-1);
}
int main()
{
    //fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        ll lcs=call(0,0);
        cout<<"Case "<<tt++<<": "<<lcs<<in<<call2(0,0,lcs)<<endl;

    }
    return 0;
}

