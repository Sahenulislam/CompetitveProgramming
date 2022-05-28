#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=2e5+2;
vector<ll>graph[mxn];
ll Level[mxn],Parent[mxn];
ll ST[mxn][70];
ll n;
void DFS(ll u,ll p)
{
    for(auto v:graph[u])
    {
        if(v!=p)
        {
            Level[v]=Level[u]+1;
            DFS(v,u);
        }
    }
}

void SparseTable()
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

ll LCA(ll u,ll L)
{
    ll log;
    if(Level[u]<L)
        return -1;
    while(L>0)
    {
        log=log2(L);
        u=ST[u][log];
        L-=(1<<log);
    }
    return u;
}
int main()
{
    ll q,u,v,L;
    cin>>n>>q;
    Parent[1]=-1;
    Level[1]=0;
    for(ll i=2; i<=n; i++)
    {
        cin>>u;
        Parent[i]=u;
        graph[u].push_back(i);
        graph[i].push_back(u);
    }
    DFS(1,-1);
    SparseTable();
    while(q--)
    {
        cin>>u>>L;
        cout<<LCA(u,L)<<endl;
    }
    return 0;
}
