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
const ll mxn=1e5+10;
vector<ll>g[mxn+10];
ll sp[mxn+10][25];
ll pa[mxn+10];
ll level[mxn+10];
ll value[mxn+10];
void dfs(ll u,ll p)
{
    for(auto v:g[u])
    {
        if(v!=p)
        {
            pa[v]=u;
            level[v]=level[u]+1;
            dfs(v,u);
        }
    }
}

void sparsetable(ll n)
{
    memset(sp,-1,sizeof(sp));
    for(ll i=0;i<n;i++)
    {
        sp[i][0]=pa[i];
    }
    for(ll i=0;(1<<i)<=n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(sp[j][i-1]!=-1)
            {
                sp[j][i]=sp[sp[j][i-1]][i-1];
            }
        }
    }
}

ll lca(ll u,ll val)
{
    ll Log=log2(level[u]);
    Log++;
    //cout<<Log<<endl;
    for(ll i=Log;i>=0;i--)
    {
        //cout<<yes<<in<<sp[u][i]<<endl;
        if(value[sp[u][i]]>=val)
            u=sp[u][i];
    }
    return u;
}

int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        value[0]=1;
        for(ll i=1;i<=n-1;i++)
        {
            ll u,v;
            cin>>u>>v;
            g[u].pb(i);
            g[i].pb(u);
            value[i]=v;
        }
        pa[0]=-1;
        dfs(0,-1);
        sparsetable(n);
        cout<<"Case "<<tt++<<":"<<endl;
        while(q--)
        {
            ll u,val;
            cin>>u>>val;
            cout<<lca(u,val)<<endl;
        }
        for(ll i=0;i<=n+2;i++)
        {
           pa[i]=0;
           level[i]=0;
           value[i]=0;
           g[i].clear();
        }
    }
    return 0;
}

