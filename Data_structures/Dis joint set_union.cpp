#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define endl "\n";
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
