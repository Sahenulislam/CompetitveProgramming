/*     Count Strongly Connected Component
       & Print All Component
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back

const ll mxn=2e5+10;
vector<ll>g[mxn+10],ing[mxn+10];
vector<vector<ll>>scc;
ll vist[mxn+10],ans[mxn+10];
vector<ll>topo,temp;

void topsort(ll u)
{
    vist[u]=1;
    for(auto v:g[u])
    {
        if(!vist[v])
            topsort(v);
    }
    topo.pb(u);
}

void SCC(ll u)
{
    vist[u]=1;
    for(auto v:ing[u])
    {
        if(!vist[v])
            SCC(v);
    }
    temp.pb(u);
}


int main()
{
    ll n,m,u,v;
    cin>>n>>m;
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v;
        g[u].pb(v);
        ing[v].pb(u);
    }
    for(ll i=1; i<=n; i++)
    {
        if(!vist[i])
            topsort(i);
    }
    ll cnt=0;
    reverse(topo.begin(),topo.end());
    memset(vist,0,sizeof(vist));
    for(ll i=0; i<topo.size(); i++)
    {
        if(!vist[topo[i]])
        {
            cnt++;
            SCC(topo[i]);
            scc.pb(temp);
            temp.clear();
        }
    }
    cout<<cnt<<endl;
    ll x=0;
    for(ll i=0; i<scc.size(); i++)
    {
        x++;
        for(ll j=0; j<scc[i].size(); j++)
        {
            ans[scc[i][j]]=x;
        }
    }
    for(ll i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}

