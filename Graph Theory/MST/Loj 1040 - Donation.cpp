#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const ll mxn=60;
vector<pair<ll,pair<ll,ll>>>g;
vector<ll>temp[mxn+10];
ll pa[mxn+10],vist[mxn+10];

void make_set()
{
    for(ll i=0; i<=mxn+2; i++)
        pa[i]=i;

}

ll Find(ll u)
{
    if(u==pa[u])
        return u;
    else return pa[u]=Find(pa[u]);
}

ll unio(ll u,ll v)
{
    u=Find(u);
    v=Find(v);
    if(u!=v)
    {
        pa[v]=u;
        return 1;
    }
    else
        return 0;
}
ll mst()
{
    ll ans=0;
    for(auto i:g)
    {
        ll wt=i.first;
        ll u=i.second.first;
        ll v=i.second.second;
        if(unio(u,v))
            ans+=wt;
    }
    return ans;
}



void dfs(ll u)
{
    vist[u]=1;
    for(auto v:temp[u])
    {
        if(!vist[v])
            dfs(v);
    }
}


int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        for(ll i=0;i<=mxn+2;i++)
        {
            vist[i]=0;
            temp[i].clear();
        }
        make_set();
        g.clear();
        ll n,x,cnt=0,ans=0;
        cin>>n;
        ll a[n+10][n+10];
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                cin>>x;
                ans+=x;
                if(x!=0)
                {
                    g.pb({x,{i,j}});
                    temp[i].pb(j);
                    temp[j].pb(i);
                }

            }
        }
        for(ll i=1; i<=n; i++)
        {
            if(!vist[i])
            {
                cnt++;
                dfs(i);
            }
        }
        cout<<"Case "<<tt++<<": ";
        if(cnt>1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        sort(g.begin(),g.end());
        ll tempans=mst();
        cout<<ans-tempans<<endl;
    }
    return 0;
}

