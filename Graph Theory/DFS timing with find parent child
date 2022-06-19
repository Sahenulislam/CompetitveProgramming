/*
     Given a Graph
     Each query given 2 node U,V
     if U is parent of V print yes
     otherwise print no
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const ll mxn=1e5;
vector<ll>g[mxn+10];
ll Start[mxn+10],End[mxn+10],Time=0;
void dfs(ll u,ll pa=-1)
{
    Start[u]=++Time;
    for(auto v: g[u])
    {
        if(v!=pa)
        {
            dfs(v,u);
        }
    }
    End[u]=Time;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll u,v;
        for(ll i=0; i<n-1; i++)
        {
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1);
        ll q;
        cin>>q;
        while(q--)
        {
            cin>>u>>v;
            if(Start[u]<=Start[v]&&End[v]<=End[u])
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    }
}
