// Lightoj 1257 - Farthest Nodes in a Tree (II)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=3e4+10;
vector<pair<ll,ll>>g[mxn+10];
ll cost1[mxn+10],cost2[mxn+10];
void dijstra1(ll n,ll k)
{
    for(ll i=0; i<=n; i++)
    {
        cost1[i]=1e18;
    }
    cost1[k]=0;
    priority_queue<pair<ll,ll>>q;
    q.push({0,k});
    while(!q.empty())
    {
        ll wt=-q.top().first;
        ll u=q.top().second;
        q.pop();
        if(cost1[u]<wt)continue;
        for(auto i: g[u])
        {
            ll wtt=i.second;
            ll v=i.first;
            if(wtt+wt<cost1[v])
            {
                cost1[v]=wtt+wt;
                q.push({-cost1[v],v});
            }
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
        dijstra1(n,0);
        for(ll i=0; i<n; i++)
        {
            if(mx<cost1[i])
            {
                mx=cost1[i];
                mxnode=i;
            }
        }
        mx=-1;
        dijstra1(n,mxnode);
        for(ll i=0; i<n; i++)
        {
            cost2[i]=cost1[i];
            if(mx<cost1[i])
            {
                mx=cost1[i];
                mxnode=i;
            }
        }
        dijstra1(n,mxnode);
        cout<<"Case "<<tt++<<":"<<endl;
        for(ll i=0;i<n;i++)
        {
            cout<<max(cost1[i],cost2[i])<<endl;
        }
        for(ll i=0;i<=mxn;i++)
        {
            g[i].clear();
        }

    }
    return 0;
}
