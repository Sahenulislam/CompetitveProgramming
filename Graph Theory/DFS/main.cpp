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
#define nl "\n"
#define siz(pir) (ll)pir.size()
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}

vector<ll>g[110],vc;
ll vis[110];
ll f=0,cnt=0;

void dfs(ll u,ll pa)
{
    vc.pb(u);
    vis[u]=1;
    for(auto v:g[u])
    {
        if(pa==v)continue;
        if(vis[v]==0)
            dfs(v,u);
        else
            f=1;
    }
}

int main()
{
    fast
    ll n,m;
    cin>>n>>m;
    set<ll>st;
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        st.insert(u);
        st.insert(v);


    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(!st.count(i))continue;
        if(vis[i]==0)
        {
            vc.clear();
            f=0;
            dfs(i,-1);
            if((vc.size()&1)&&f)
                ans++;


        }
    }
    if(n%2==0&&ans%2!=0)ans++;
    else if(n%2!=0&&ans%2==0)ans++;
    cout<<ans<<nl;
    return 0;
}
