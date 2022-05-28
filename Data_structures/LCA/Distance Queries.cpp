#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll mxn=2e5+2;
vector<ll>graph[mxn];
ll Level[mxn],Parent[mxn];
ll ST[mxn][70];
void DFS(ll u,ll p)
{
    for(auto v:graph[u])
    {
        if(v!=p)
        {
            Parent[v]=u;
            Level[v]=Level[u]+1;
            DFS(v,u);
        }
    }
}

void SparseTable(ll n)
{
    memset(ST,-1,sizeof(ST));
    for(ll i=1; i<=n; i++)
        ST[i][0]=Parent[i];
    for(ll j=1; (1<<j)<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            if(ST[i][j-1]!=-1)
                ST[i][j]=ST[ST[i][j-1]][j-1];
        }
    }
}

ll LCA(ll u,ll v)
{
    if(Level[u]<Level[v])
        swap(u,v);
    ll log=log2(Level[u]);
    for(ll j=log; j>=0; j--)
    {
        if(Level[u]-(1<<j)>=Level[v])
            u=ST[u][j];
    }
    if(u==v)return u;
    for(ll j=log; j>=0; j--)
    {
        if(ST[u][j]!=ST[v][j])
        {
            u=ST[u][j];
            v=ST[v][j];
        }
    }
    return Parent[u];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,u,v;
    cin>>n>>q;
    Parent[n]=-1;
    Level[n]=0;
    for(ll i=0; i<n-1; i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(n,-1);
    SparseTable(n);
    while(q--)
    {
        cin>>u>>v;
        ll lca=LCA(u,v);
        cout<<Level[u]+Level[v]-(2*Level[lca])<<endl;
    }
    return 0;
}
