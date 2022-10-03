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
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}


string s;
ll dp[55][10][10];
ll cnt=0;
ll call(ll i,ll vo,ll con)
{
    if(vo==3)
    {
        cnt++;
        return 0;
    }
    if(con==5)
    {
        cnt++;
        return 0;
    }
    if(i>=s.size())return 1;
    if(dp[i][vo][con]!=-1)return dp[i][vo][con];
    if(s[i]=='0')return dp[i][vo][con]=call(i+1,vo+1,0);
    if(s[i]=='1')return dp[i][vo][con]=call(i+1,0,con+1);
    return dp[i][vo][con]=max(call(i+1,vo+1,0),call(i+1,0,con+1));
}

int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        cnt=0;
        string x;
        cin>>x;
        s.clear();
        for(ll i=0; i<x.size(); i++)
        {
            if(x[i]=='A'||x[i]=='E'||x[i]=='I'||x[i]=='O'||x[i]=='U')
                s+='0';
            else if(x[i]=='?')
                s+=x[i];
            else
                s+='1';
        }
        memset(dp,-1,sizeof(dp));
        ll ans=call(0,0,0);
        if(ans==1&&cnt!=0)
            cout<<"Case "<<tt++<<": MIXED"<<endl;
        else if(ans==1&&cnt==0)
            cout<<"Case "<<tt++<<": GOOD"<<endl;
        else
            cout<<"Case "<<tt++<<": BAD"<<endl;


        //cout<<f<<endl;
    }
    return 0;
}


