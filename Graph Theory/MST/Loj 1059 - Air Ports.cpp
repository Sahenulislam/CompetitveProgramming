#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printv(x) for(ll i=0;i<x.size();i++){if(i+1==x.size())cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define printa(x,n) for(ll i=0;i<n;i++){if(i+1==n)cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define pb push_back

const ll mxn=1e5+10;

vector<pair<ll,pair<ll,ll>>>vc;
ll parent[mxn+10];
ll vi[mxn+10];
vector<ll>g[mxn+10];

void Make_set()
{
    for(ll i=0; i<=mxn+2; i++)
    {
        vi[i]=0;
        parent[i]=i;
        g[i].clear();
    }
    vc.clear();
}

ll Find(ll u)
{
    if(u==parent[u])return u;
    else return parent[u]=Find(parent[u]);
}

void DFS(ll u)
{
    vi[u]=1;
    for(auto v:g[u])
    {
        if(vi[v]==0)
            DFS(v);
    }
}
ll Union(ll u,ll v)
{
    u=Find(u);
    v=Find(v);
    if(u!=v)
    {
        parent[v]=u;
        return 1;
    }
    else return 0;
}
void MST(ll n,ll k)
{
    ll sum=0,cnt=0;
    vector<ll>vv;
    for(ll i=0; i<vc.size(); i++)
    {
        ll cost=vc[i].first;
        ll u=vc[i].second.first;
        ll v=vc[i].second.second;
        if(Union(u,v)==1)
        {
            sum+=cost;
            vv.pb(cost);
            g[u].pb(v);
            g[v].pb(u);
        }
    }
    for(ll i=1; i<=n; i++)
    {
        if(vi[i]==0)
        {
            cnt++;
            sum+=k;
            DFS(i);
        }
    }
    sort(vv.rbegin(),vv.rend());
    for(ll i=0; i<vv.size(); i++)
    {
        if(vv[i]>=k)
        {
            cnt++;
            sum+=k;
            sum-=vv[i];
        }
    }
    cout<<sum<<" "<<cnt<<endl;
}

int main()
{
    //fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        Make_set();
        for(ll i=0; i<m; i++)
        {
            ll u,v,cost;
            cin>>u>>v>>cost;
            vc.pb({cost,{u,v}});
        }
        sort(vc.begin(),vc.end());
        cout<<"Case "<<tt++<<": ";
        MST(n,k);
    }
    return 0;
}

