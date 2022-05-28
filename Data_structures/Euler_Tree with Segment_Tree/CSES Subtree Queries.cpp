#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=2e5;
vector<ll>g[mxn+3];
ll sttime[mxn+3],fintime[mxn+3],a[mxn+3],st[mxn*4],valu[mxn+3];
ll tim=0;
ll vist[mxn+3];
void dfs(ll u)
{
    sttime[u]=++tim;
    vist[u]=1;
    for(auto v:g[u])
    {
        if(!vist[v])
        dfs(v);
    }
    fintime[u]=tim;
}
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        st[cur]=valu[a[left]];
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    st[cur]=st[cur*2]+st[cur*2+1];
}
void update(ll cur,ll left,ll right,ll pos,ll val)
{
    if(pos<left||pos>right)return;
    if(pos<=left&&pos>=right)
    {
        st[cur]=val;
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,pos,val);
    update(cur*2+1,mid+1,right,pos,val);
    st[cur]=st[cur*2]+st[cur*2+1];
}
ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(r<left||l>right)return 0;
    if(l<=left&&r>=right)
    {
        return st[cur];
    }
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return (x+y);
}
int main()
{
    ll n,q;
    cin>>n>>q;
    ll u,v;
    for(ll i=1; i<=n; i++)
    {
        cin>>valu[i];
    }
    for(ll i=1; i<=n-1; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    dfs(1);
    vector<pair<ll,ll>>ve;
    for(ll i=1; i<=n; i++)
    {
        ve.push_back({sttime[i],i});
    }
    sort(ve.begin(),ve.end());
    for(ll i=0; i<ve.size(); i++)
    {
        a[ve[i].first]=ve[i].second;
    }
    build(1,1,n);
    while(q--)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            ll val;
            cin>>u>>val;
            ll atime=sttime[u];
            update(1,1,n,atime,val);
        }
        else
        {
            ll d;
            cin>>d;
            ll x=sttime[d];
            ll y=fintime[d];
            ll ans=query(1,1,n,x,y);
            cout<<ans<<endl;
        }
    }
    return 0;
}

