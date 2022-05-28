#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll mxn=3*10e4;
ll sttime[mxn+3],fintime[mxn+3],vist1[mxn+3],valu[mxn*2+4],a[mxn*2+4];
vector<ll>g[mxn+4];
ll tim=0;
// DFS for generate start time & ending time
void dfs_for_timeing(ll u)
{
    vist1[u]=1;
    sttime[u]=++tim;
    for(auto v:g[u])
    {
        if(!vist1[v])
        {
            dfs_for_timeing(v);
        }
    }
    fintime[u]=++tim;
}

// Segment Tree to Point Update & Query
ll st[mxn*4];
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
        valu[a[pos]]=val;
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

// LCA
ll vist2[mxn+3],sptb[mxn+3][30],level[mxn+3],pa[mxn+3];
void dfs_for_parent(ll u)
{
    vist2[u]=1;
    for(auto v:g[u])
    {
        if(!vist2[v])
        {
            level[v]=level[u]+1;
            pa[v]=u;
            dfs_for_parent(v);
        }
    }
}

ll sparsetable(ll n)
{
    memset(sptb,-1,sizeof(sptb));
    for(ll i=0; i<n; i++)
    {
        sptb[i][0]=pa[i];
    }
    for(ll i=1; (1<<i)<=n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            sptb[j][i]=sptb[sptb[j][i-1]][i-1];
        }
    }
}
ll lca(ll u,ll v)
{
    if(level[u]<level[v])
        swap(u,v);
    ll log=log2(level[u]);
    for(ll i=log; i>=0; i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            u=sptb[u][i];
        }
    }
    if(u==v)return u;
    for(ll i=log; i>=0; i--)
    {
        if(sptb[u][i]!=sptb[v][i])
        {
            u=sptb[u][i];
            v=sptb[v][i];
        }
    }
    return pa[u];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll u,v;
        for(ll i=0; i<n; i++)
        {
            cin>>valu[i];
        }
        for(ll i=0; i<n-1; i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs_for_timeing(0);
        vector<pair<ll,ll>>ve;
        for(ll i=0; i<n; i++)
        {
            ve.push_back({sttime[i],i});
        }
        for(ll i=0; i<n; i++)
        {
            ve.push_back({fintime[i],-i});
        }
        sort(ve.begin(),ve.end());
        a[ve[0].first]=ve[0].second;
        for(ll i=1; i<ve.size(); i++)
        {
            if(ve[i].second<=0)
            {
                ll temp=-ve[i].second;
                a[ve[i].first]=n+temp;
                valu[n+temp]=-valu[temp];
            }
            else
            {
                a[ve[i].first]=ve[i].second;
            }
        }
        build(1,1,n*2);
        level[0]=0;
        pa[0]=1;
        dfs_for_parent(0);
        sparsetable(n);
        ll q;
        cin>>q;
        cout<<"Case "<<tt++<<": "<<endl;
        while(q--)
        {
            ll x,ans;
            cin>>x;
            if(x==1)
            {
                ll pos,val;
                cin>>pos>>val;
                ll timestart=sttime[pos];
                ll timeend=fintime[pos];
                update(1,1,n*2,timestart,val);
                update(1,1,n*2,timeend,-val);
            }
            else
            {
                ll u,v;
                cin>>u>>v;
                ll lc=lca(u,v);
                if(lc==u||lc==v)
                {
                    if(lc==u)
                    {
                        ans=query(1,1,n*2,sttime[lc],sttime[v]);
                    }
                    else
                    {
                        ans=query(1,1,n*2,sttime[lc],sttime[u]);
                    }
                }
                else
                {
                    ans=query(1,1,n*2,sttime[lc],sttime[u])+query(1,1,n*2,sttime[lc],sttime[v])-valu[lc];
                }
                cout<<ans<<endl;
            }
        }
        for(ll i=0; i<=mxn; i++)
        {
            tim=0;
            level[i]=0;
            pa[i]=0;
            g[i].clear();
            vist1[i]=0;
            vist2[i]=0;
            sttime[i]=0;
            fintime[i]=0;
        }
        memset(st,0,sizeof(st));
        memset(a,0,sizeof(a));
        memset(valu,0,sizeof(valu));
    }
    return 0;
}

