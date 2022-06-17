#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        1e9
#define in " "
#define pb push_back

const ll mxn=1e5+10;
ll sptb[mxn+10][25],sptbmx[mxn+10][25],sptbmn[mxn+10][25];
ll pa[mxn+10];
ll level[mxn+10];
vector<pair<ll,ll>>g[mxn+10];
void dfs(ll u,ll p)
{
    for(auto V:g[u])
    {
        ll v=V.first;
        ll cost=V.second;
        if(v!=p)
        {
            level[v]=level[u]+1;
            sptb[v][0]=u;
            sptbmx[v][0]=cost;
            sptbmn[v][0]=cost;
            pa[v]=u;
            dfs(v,u);
        }
    }
}

void Build_SparseTable(ll n)
{
    for(ll i=1; (1<<i)<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            sptb[j][i]=sptb[sptb[j][i-1]][i-1];
            sptbmx[j][i]=max(sptbmx[j][i-1],sptbmx[sptb[j][i-1]][i-1]);
            sptbmn[j][i]=min(sptbmn[j][i-1],sptbmn[sptb[j][i-1]][i-1]);
        }
    }
}

ll LCA(ll u,ll v)
{
    if(level[u]<level[v])
        swap(u,v);
    ll log=log2(level[u]);
    log++;
    for(ll i=log; i>=0; i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            u=sptb[u][i];
        }

    }
    if(u==v)return u;
    for(ll i=log; i>=0; i--)
    {
        if(sptb[u][i]!=-1&&sptb[u][i]!=sptb[v][i])
        {
            u=sptb[u][i];
            v=sptb[v][i];
        }
    }
    return pa[u];
}
ll LCA_Min(ll u,ll v)
{
    ll mn=INF;
    if(level[u]<level[v])
        swap(u,v);
    ll log=log2(level[u]);
    log++;
    for(ll i=log; i>=0; i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            mn=min(sptbmn[u][i],mn);
            u=sptb[u][i];
        }
    }
    return mn;
}
ll LCA_Max(ll u,ll v)
{
    ll mx=-1;
    if(level[u]<level[v])
        swap(u,v);
    ll log=log2(level[u]);
    log++;
    for(ll i=log; i>=0; i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            mx=max(sptbmx[u][i],mx);
            u=sptb[u][i];
        }
    }
    return mx;
}

int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,u,v,cost;
        cin>>n;
        for(ll i=0; i<n-1; i++)
        {
            cin>>u>>v>>cost;
            g[u].pb({v,cost});
            g[v].pb({u,cost});
        }
        dfs(1,-1);
        Build_SparseTable(n);
        ll q;
        cin>>q;
        cout<<"Case "<<tt++<<": "<<endl;
        while(q--)
        {
            cin>>u>>v;
            ll lca=LCA(u,v);
            if(lca==u||lca==v)
            {
                if(lca==u)
                {
                    cout<<LCA_Min(lca,v)<<in<<LCA_Max(lca,v)<<endl;
                }
                else
                {
                    cout<<LCA_Min(lca,u)<<in<<LCA_Max(lca,u)<<endl;
                }
            }
            else
            {
                ll mx1,mx2;
                ll mn1,mn2;
                mx1=LCA_Max(lca,u);
                mx2=LCA_Max(lca,v);
                mn1=LCA_Min(lca,u);
                mn2=LCA_Min(lca,v);
                cout<<min(mn1,mn2)<<in<<max(mx1,mx2)<<endl;
            }

        }
        for(ll i=1; i<=n+4; i++)
        {
            for(ll j=0; j<=20; j++)
            {
                sptb[i][j]=-1;
                sptbmx[i][j]=-1;
                sptbmn[i][j]=INF;
            }
            g[i].clear();
        }
        memset(level,0,sizeof(level));
        memset(pa,0,sizeof(pa));
    }
    return 0;
}

