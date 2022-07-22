#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=2e5+10;
vector<ll>g[mxn+10],vc[mxn+10];
ll parent[mxn+10];
ll vis[mxn+10],cnt=0;

void cycle(ll snode,ll enode,ll cnt)
{
    vc[cnt].push_back(enode);
    while(snode!=enode)
    {
        vc[cnt].push_back(snode);
        snode=parent[snode];
    }
    vc[cnt].push_back(enode);
    reverse(vc[cnt].begin(),vc[cnt].end());
}

void DFS(ll u,ll pa=-1)
{
    vis[u]=1;
    for(auto v:g[u])
    {
        if(vis[v]==0)
        {
            parent[v]=u;
            DFS(v,u);
        }
        else if(vis[v]==1&&v!=pa)
        {
            ll snode=u;
            ll enode=v;
            cycle(snode,enode,cnt);
            cnt++;
        }
    }
    vis[u]=2;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=0; i<m; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(ll i=1; i<=n; i++)
    {
        if(vis[i]==0)
            DFS(i);
    }
    if(cnt==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    cout<<"Number of Cycle: "<<cnt<<endl;
    for(ll i=0;i<cnt;i++)
    {
        cout<<"Cycle Number "<<i+1<<": ";
        for(auto v:vc[i])
            cout<<v<<" ";
        cout<<endl;
    }

    return 0;
}


