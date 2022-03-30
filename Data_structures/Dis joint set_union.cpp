#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxx=1e6;
ll parent[mxx+10],mn[mxx+10],mx[mxx+10],siz[mxx+10];
void make_set(ll n)
{
    for(ll i=1; i<=n; i++)
    {
        parent[i]=i;
        mn[i]=i;
        mx[i]=i;
        siz[i]=1;
    }
}

ll find(ll x)
{
    if(x==parent[x])
        return x;
    return parent[x]=find(parent[x]);
}

void unio(ll u,ll v)
{
    u=find(u);
    v=find(v);
    if(u!=v)
    {
        if(siz[u]<siz[v])
            swap(u,v);
        mn[u]=min(mn[u],mn[v]);
        mx[u]=max(mx[u],mx[v]);
        siz[u]+=siz[v];
        parent[v]=u;
    }
}

int main()
{
    fast
    ll n,m,a,b;
    string s;
    cin>>n>>m;
    make_set(n);
    for(ll i=0; i<m; i++)
    {
        cin>>s;
        if(s=="union")
        {
            cin>>a>>b;
            unio(a,b);
        }
        else if(s=="get")
        {
            cin>>a;
            ll k=find(a);
            cout<<mn[k]<<in<<mx[k]<<in<<siz[k]<<endl
        }
    }
    return 0;
}

// CSES Road Reparation//
/*

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll mxn=1e5;
ll parent[mxn+3],siz[mxn+3],com,mx=1;
void init(ll n)
{
    for(ll i=1;i<=n;i++)
    {
        parent[i]=i;
        siz[i]=1;
    }
}

ll sett(ll x)
{
    if(x==parent[x])
        return x;
    return parent[x]=sett(parent[x]);
}

void join(ll u,ll v)
{
    ll uu=sett(u);
    ll vv=sett(v);
    if(uu!=vv)
    {
        com--;
        if(siz[uu]<siz[vv])
            swap(uu,vv);
        siz[uu]+=siz[vv];
        mx=max(siz[uu],mx);
        parent[vv]=uu;
    }
}
int main()
{
    ll n,m,u,v;
    cin>>n>>m;
    init(n);
    vector<pair<ll,ll>>g;
    com=n;
    for(ll i=0;i<m;i++)
    {
        cin>>u>>v;
        g.pb({u,v});
    }
    for(ll i=0;i<m;i++)
    {
        ll u=g[i].first;
        ll v=g[i].second;
        join(u,v);
        cout<<com<<" "<<mx<<endl;
    }

}
*/

