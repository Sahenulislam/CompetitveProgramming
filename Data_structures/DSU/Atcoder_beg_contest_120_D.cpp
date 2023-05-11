#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printv(x) for(ll i=0;i<x.size();i++){if(i+1==x.size())cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define printa(x,n) for(ll i=0;i<n;i++){if(i+1==n)cout<<x[i]<<endl;else cout<<x[i]<<" ";}
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
#define nl "\n"
#define siz(pir) (ll)pir.size()
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
const ll mxn=1e5+10;

ll siz[mxn+10];
ll pa[mxn+10];
ll ans=0;

ll join(ll u)
{
    if(pa[u]==u)return u;
    return pa[u]=join(pa[u]);
}

void unio(ll u,ll v)
{
    u=join(u);
    v=join(v);
    if(v!=u)
    {
        ans-=siz[u]*siz[v];
        siz[u]+=siz[v];
        pa[v]=u;
    }
}

int main()
{
    fast
    for(ll i=0; i<=mxn; i++)
    {
        siz[i]=1;
        pa[i]=i;
    }
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>vc;
    for(ll i=0; i<m; i++)
    {
        ll u,v;
        cin>>u>>v;
        vc.pb({u,v});
    }
    vector<ll>vv;
    ans=(n*(n-1))/2;
    for(ll i=vc.size()-1; i>=0; i--)
    {
        vv.pb(ans);
        ll u=vc[i].first;
        ll v=vc[i].second;
        unio(u,v);


    }
    for(ll i=vv.size()-1;i>=0;i--)
        cout<<vv[i]<<nl;

    return 0;
}

