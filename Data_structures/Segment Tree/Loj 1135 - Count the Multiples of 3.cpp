#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const ll mxn=1e5+10;
ll seg[4*mxn][5],lazy[mxn*4],a[mxn+10];

void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        seg[cur][0]=1;
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    for(ll i=0; i<3; i++)
    {
        seg[cur][i]=seg[cur*2][i]+seg[cur*2+1][i];
    }
}

void pushdown(ll cur,ll left,ll right)
{
    if(lazy[cur]!=0)
    {
        ll cnt=lazy[cur]%3;
        ll temp[5];
        for(ll i=0; i<3; i++)
            temp[i]=seg[cur][i];
        for(ll i=0; i<3; i++)
            seg[cur][i]=temp[(i-cnt+3)%3];
        if(cnt!=0&&left!=right)
        {
            lazy[cur*2]=lazy[cur*2]+lazy[cur];
            lazy[cur*2+1]=lazy[cur*2+1]+lazy[cur];
        }
    }
    lazy[cur]=0;
}

void update(ll cur,ll left,ll right,ll l,ll r)
{
    if(lazy[cur]!=0)pushdown(cur,left,right);
    if(left>r||right<l)return;
    if(l<=left&&right<=r)
    {
        lazy[cur]++;
        pushdown(cur,left,right);
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,l,r);
    update(cur*2+1,mid+1,right,l,r);
    for(ll i=0; i<3; i++)
    {
        seg[cur][i]=seg[cur*2][i]+seg[cur*2+1][i];
    }
}

ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(lazy[cur]!=0)pushdown(cur,left,right);
    if(left>r||right<l)return 0;
    if(l<=left&&right<=r)
    {
        return seg[cur][0];
    }
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return (x+y);
}
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        build(1,0,n-1);
        cout<<"Case "<<tt++<<":"<<endl;
        while(q--)
        {
            ll m,x,y;
            cin>>m;
            if(m==0)
            {
                cin>>x>>y;
                update(1,0,n-1,x,y);
            }
            else
            {
                cin>>x>>y;
                cout<<query(1,0,n-1,x,y)<<endl;
            }
        }
        memset(seg,0,sizeof(seg));
        memset(lazy,0,sizeof(lazy));
    }
    return 0;
}
