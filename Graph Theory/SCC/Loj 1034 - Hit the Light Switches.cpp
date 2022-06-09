#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll mxn=50000+10;
vector<ll>g[mxn+10];
ll vist[mxn+10];
vector<ll>topo;
void topsort(ll u)
{
    vist[u]=1;
    for(auto v:g[u])
    {
        if(!vist[v])
            topsort(v);
    }
    topo.pb(u);
}

void dfs(ll u)
{
    vist[u]=1;
    for(auto v:g[u])
    {
        if(!vist[v])
            dfs(v);
    }
}


int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,m,u,v,ans=0;
        cin>>n>>m;
        for(ll i=0; i<n+10; i++)
        {
            g[i].clear();
            vist[i]=0;
        }
        topo.clear();
        for(ll i=0; i<m; i++)
        {
            cin>>u>>v;
            g[u].pb(v);
        }
        for(ll i=1; i<=n; i++)
        {
            if(!vist[i])
                topsort(i);
        }
        reverse(topo.begin(),topo.end());
        for(ll i=0; i<n+10; i++)
        {
            vist[i]=0;
        }
        for(ll i=0; i<topo.size(); i++)
        {
            if(!vist[topo[i]])
            {
                ans++;
                dfs(topo[i]);
            }
        }
        cout<<"Case "<<tt++<<": "<<ans<<endl;
    }
    return 0;
}

