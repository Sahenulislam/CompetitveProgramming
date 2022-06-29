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
const ll mxn=3e5+10;
vector<ll>g[mxn+10],g1[mxn+10];
ll Start[mxn+10],low[mxn+10];
ll vi[mxn+10];
ll Time=0;
set<pair<ll,ll>>st;
ll flag=0;
void dfs(ll u,ll pa=-1)
{
    vi[u]=1;
    Start[u]=++Time;
    low[u]=Start[u];
    for(auto v:g[u])
    {
        if(vi[v]==0)
        {
            g1[u].pb(v);
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>Start[u])
            {
                flag=1;
            }
        }
        else if(v!=pa)
        {
            low[u]=min(low[u],Start[v]);
            if(st.find({u,v})==st.end()&&st.find({v,u})==st.end())
            {
                st.insert({u,v});
                g1[u].pb(v);
            }

        }
    }
}
ll Find(ll u)
{
    if(low[u]==u)return u;
    else return low[u]=Find(low[u]);
}

int main()
{
    //fast
    ll n,m;
    cin>>n>>m;
    ll u,v;
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    if(flag==0)
    {
        for(ll u=1; u<=n; u++)
        {
            for(auto v:g1[u])
            {
                cout<<u<<in<<v<<endl;
            }
        }
    }
    else
        cout<<zero<<endl;
    return 0;
}
