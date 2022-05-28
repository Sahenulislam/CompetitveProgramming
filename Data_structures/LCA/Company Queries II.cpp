#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=2e5+2;
vector<ll>graph[mxn];
ll Level[mxn],Parent[mxn];
ll ST[mxn][70];
ll n;
void DFS(ll u,ll p)      // level and parent of every nodes
{
    for(auto v:graph[u])
    {
        if(v!=p)
        {
            //Parent[v]=u;
            Level[v]=Level[u]+1;
            DFS(v,u);
        }
    }
}

void SparseTable()
{
    memset(ST,-1,sizeof(ST));
    for(ll i=1; i<=n; i++)             // every nodes 1st parent
        ST[i][0]=Parent[i];
    for(ll j=1; (1<<j)<=n; j++)        // building sparse table of 1st, 2nd, 4th, 8th parent of ith nodes;
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
        swap(u,v);          // Always get max level in u node

    ll log=log2(Level[u]);   // Maximum 2s power of u node
    log++;

    for(ll j=log; j>=0; j--)  // For getting same level of u,v;
    {
        if(Level[u]-(1<<j)>=Level[v])
            u=ST[u][j];
    }

    if(u==v)
        return u;
    for(ll j=log; j>=0; j--)
    {
        if(ST[u][j]!=-1&&ST[u][j]!=ST[v][j])
            u=ST[u][j],v=ST[v][j];
    }
    return Parent[u];
}
int main()
{
    ll q,u,v;
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
        cin>>u>>v;
        cout<<LCA(u,v)<<endl;
    }
    return 0;
}
