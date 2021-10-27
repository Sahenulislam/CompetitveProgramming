// CSES_Graph section_Shortest Routes II
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll cost[510][510];
vector<pair<ll,ll>>g[510];

void floyd_warshall(ll u,ll n)
{
    for(ll k=1; k<=n; k++)
    {
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }
}
int main()
{
    ll n,m,q,a,b,c,k;
    cin>>n>>m>>q;
    for(ll i=0; i<=n+1; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(i==j)
                cost[i][j]=0;
            else
                cost[i][j]=1e18;
        }
    }
    for(ll i=0; i<m; i++)
    {
        cin>>a>>b>>c;
        cost[a][b]=min(cost[a][b],c);
        cost[b][a]=min(cost[b][a],c);
    }
    dijstra(1,n);
    for(ll i=0; i<q; i++)
    {
        cin>>a>>b;
        if(cost[a][b]==1e18)
            cout<<mone<<endl;
        else
            cout<<cost[a][b]<<endl;
    }
    return 0;
}
