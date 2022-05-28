#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=3e4+10;
vector<pair<ll,ll>>g[mxn+10];
ll cost1[mxn+10],cost2[mxn+10];
void dfs(ll u,ll p)
{
    for(auto i: g[u])
    {
        ll wt=i.second;
        ll v=i.first;
        if(v!=p)
        {
            cost1[v]=cost1[u]+wt;
            dfs(v,u);
        }

    }
}
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,u,v,w;
        cin>>n;
        for(ll i=0; i<n-1; i++)
        {
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        ll mx=-1,mxnode;
        cost1[0]=0;
        dfs(0,-1);
        for(ll i=0; i<n; i++)
        {
            if(mx<cost1[i])
            {
                mx=cost1[i];
                mxnode=i;
            }
        }
        mx=-1;
        cost1[mxnode]=0;
        dfs(mxnode,-1);
        for(ll i=0; i<n; i++)
        {
            cost2[i]=cost1[i];
            if(mx<cost1[i])
            {
                mx=cost1[i];
                mxnode=i;
            }
        }
        cost1[mxnode]=0;
        dfs(mxnode,-1);
        cout<<"Case "<<tt++<<":"<<endl;
        for(ll i=0; i<n; i++)
        {
            cout<<max(cost1[i],cost2[i])<<endl;
        }
        for(ll i=0; i<=mxn; i++)
        {
            g[i].clear();
        }

    }
    return 0;
}

