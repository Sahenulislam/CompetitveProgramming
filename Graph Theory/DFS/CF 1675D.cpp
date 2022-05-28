#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back

const ll mxn=2e5+10;
vector<ll>path[mxn+10],g[mxn+10];
ll cnt=0;
void dfs(ll u,ll p)
{
    for(auto v: g[u])
    {


        if(v!=p)
        {
            path[cnt].pb(v);
            dfs(v,u);
        }
    }
    if(path[cnt].size()!=0)
        cnt++;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,root,v;
        cin>>n;
        ll a[n+10];
        for(ll i=1; i<=n; i++)
        {
            cin>>v;
            if(i==v){
                root=i;
                continue;
            }
            g[i].pb(v);
            g[v].pb(i);
        }
        cnt=0;
        path[cnt].pb(root);
        dfs(root,-1);
        cout<<cnt<<endl;
        for(ll i=0;i<cnt;i++)
        {
            cout<<path[i].size()<<endl;
            for(ll j=0;j<path[i].size();j++)
            {
                cout<<path[i][j]<<" ";
            }
            cout<<endl;
        }
        for(ll i=0;i<=n+3;i++)
        {
            path[i].clear();
            g[i].clear();
        }

    }
    return 0;
}
