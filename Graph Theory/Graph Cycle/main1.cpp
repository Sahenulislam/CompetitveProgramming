#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll mxn=510;
vector<ll>g[mxn+10];
ll parent[mxn+10];
ll level[mxn+10];
ll vis[mxn+10];
ll mn=10000000;

void BFS(ll u)
{
    queue<ll>q;
    q.push(u);
    vis[u]=1;
    level[u]=0;
    while(!q.empty())
    {
        u=q.front();

        q.pop();
        for(auto v:g[u])
        {

            if(vis[v]==0)
            {
                vis[v]=1;
                q.push(v);
                parent[v]=u;
                level[v]=level[u]+1;
            }
            else if(vis[v]==1&&v!=parent[u])
            {
                mn=min(mn,level[u]+level[v]+1);

            }
        }
        vis[u]=2;
    }
}

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        mn=10000000;
        ll n,m;
        cin>>n>>m;
        for(ll i=0; i<=n; i++)
            g[i].clear();
        for(ll i=0; i<m; i++)
        {
            ll u,v;
            cin>>u>>v;
            u++;
            v++;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(ll i=1; i<=n; i++)
        {
           for(ll i=1;i<=n;i++)
           {
                vis[i]=0;
               parent[i]=-1;

           }
            if(vis[i]==0)
                BFS(i);

        }
        if(mn==10000000)
            cout<<"Case "<<tt++<<": "<<"impossible\n";
        else
            cout<<"Case "<<tt++<<": "<<mn<<"\n";
    }


    return 0;
}

