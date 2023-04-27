#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll mxn=2e5+10;
vector<ll>g[mxn+10];
ll c[mxn+10];
vector<pair<ll,ll>>dp[mxn+10];
ll dfs(ll u,ll pa,ll k)
{
    ll siz=g[u].size();
    if(u!=1)siz--;
    for(auto x:dp[u])
    {
        if(x.second==k)
            return x.first;
    }
    if(siz==0)
        return k*c[u];
    vector<ll>extra;
    ll sum=0;
    for(auto v:g[u])
    {
        if(v!=pa)
        {
            ll x1=k/siz;
            ll x2=(k+siz-1)/siz;
            ll ans=dfs(v,u,x1);
            extra.pb(dfs(v,u,x2)-ans);
            sum+=ans;
        }
    }
    ll d=k%siz;
    sort(extra.rbegin(),extra.rend());
    for(ll i=0; i<d; i++)
        sum+=extra[i];
    dp[u].pb({k*c[u]+sum,k});
    return k*c[u]+sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        for(ll i=2; i<=n; i++)
        {
            ll u;
            cin>>u;
            g[u].pb(i);
            g[i].pb(u);
        }
        for(ll i=1; i<=n; i++)
            cin>>c[i];
        cout<<dfs(1,-1,k)<<endl;
        for(ll i=0; i<=n; i++)
        {
            dp[i].clear();
            g[i].clear();
            c[i]=0;
        }
    }
    return 0;
}
