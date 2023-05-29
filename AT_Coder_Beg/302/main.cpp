
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define nl "\n"
pair<ll,ll>CORDINATE[8]= {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
const ll mxn=4e5+10;
vector<ll>g[mxn+10];
ll vis[mxn+10];
ll level[mxn+10];
void bfs(ll u)
{
    level[u]=0;
    vis[u]=1;
    queue<ll>q;
    q.push(u);
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
                level[v]=level[u]+1;
            }
        }
    }
}
int main()
{
    fast
    ll n,m;
    cin>>n>>m;
    for(ll i=0; i<n; i++)
    {
        ll x;
        cin>>x;
        for(ll j=0; j<x; j++)
        {
            ll v;
            cin>>v;
            g[i+m+1].pb(v);
            g[v].pb(i+m+1);
        }
    }
    bfs(1LL);
    if(level[m]==0)
    {
        cout<<mone<<nl;
    }
    else
        cout<<level[m]/2-1<<nl;
    return 0;
}
