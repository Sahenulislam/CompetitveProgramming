#include <bits/stdc++.h>
using namespace std;
#define ll int
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

ll dp[16][1<<16];
ll n;
vector<pair<ll,ll>>v;
ll call(ll i,ll x,ll j)
{
    if(i>=n)
    {
        ll sum=max(abs(v[j].first-v[0].first),abs(v[j].second-v[0].second));
        return sum;
    }
    if(dp[i][x]!=-1)return dp[i][x];
    ll mn=1e8;
    for(ll k=1; k<n; k++)
    {
        ll c=1<<k;
        if(!(x&c))
        {
            mn=min(mn,max(abs(v[k].first-v[j].first),abs(v[k].second-v[j].second))+call(i+1,x|c,k));
        }
    }
    return dp[i][x]=mn;
}

int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        v.clear();
        ll x,y;
        cin>>x>>y;
        char ch[x+10][y+10];
        ll c,d;
        memset(dp,-1,sizeof(dp));
        for(ll i=0; i<x; i++)
        {
            for(ll j=0; j<y; j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]=='x')
                {
                    c=i;
                    d=j;
                }
            }
        }
        v.pb({c,d});
        for(ll i=0; i<x; i++)
        {
            for(ll j=0; j<y; j++)
            {
                if(ch[i][j]=='g')
                {
                    v.pb({i,j});
                }
            }
        }
        n=v.size();
//        for(auto x:v)
//        {
//            cout<<x.first<<in<<x.second<<endl;
//        }
        cout<<"Case "<<tt++<<": "<<call(1,1,0)<<endl;

    }
    return 0;
}

