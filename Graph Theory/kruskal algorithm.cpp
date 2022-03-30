#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void init()
{
    for(int i = 0; i < MAX; ++i)
    {
        id[i]=i;
    }
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y,m,n;
    long long cost, minimumCost = 0;
    for(int i = 0; i < edges; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        m=root(x);
        n=root(y);
        if(m!=n)
        {
            minimumCost += cost;
           id[m]=id[n];
        }
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    init();
    cin >> nodes >> edges;
    for(int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}








//CSES Road Construction

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
