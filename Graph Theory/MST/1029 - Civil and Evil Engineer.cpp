#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=20000;
struct x
{
    ll value;
    ll U;
    ll V;
} edge[mxn+10];

bool compare(x a,x b)
{
    if(a.value<b.value)
        return true;
    else
        return false;
}
ll p[mxn+10];
void make_set(ll n)
{
    for(ll i=0; i<=n; i++)
    {
        p[i]=i;
    }
}
ll find(ll u)
{
    if(u==p[u])
        return u;
    else
        return p[u]=find(p[u]);
}
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        make_set(n+10);
        ll u,v,w;
        ll i=0;
        while(cin>>u>>v>>w)
        {
            if(u==0&&v==0&&w==0)
                break;
            edge[i].value=w;
            edge[i].U=u;
            edge[i].V=v;
            i++;
        }
        ll best=0,worst=0;
        sort(edge,edge+i,compare);
        for(ll j=0; j<i; j++)
        {
            w=edge[j].value;
            u=edge[j].U;
            v=edge[j].V;
            u=find(u);
            v=find(v);
            if(u!=v)
            {
                best+=w;
                p[v]=u;
            }
        }
        make_set(n+10);
        for(ll j=i-1; j>=0; j--)
        {
            w=edge[j].value;
            u=edge[j].U;
            v=edge[j].V;
            u=find(u);
            v=find(v);
            if(u!=v)
            {
                worst+=w;
                p[v]=u;
            }
        }
        ll ans=worst+best;
        if(ans%2==0)
            cout<<"Case "<<tt++<<": "<<ans/2<<endl;
        else
            cout<<"Case "<<tt++<<": "<<ans<<"/2"<<endl;
        for(ll i=0; i<mxn; i++)
        {
            edge[i].value=0;
            edge[i].U=0;
            edge[i].V=0;
        }
    }
    return 0;
}

