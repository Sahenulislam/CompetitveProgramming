#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const ll mxn=1e5+10;
ll lazy[mxn*4],a[mxn+10];
struct
{
    ll bit[30],sum;
} seg[mxn*4];
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        for(ll i=0; i<=22; i++)
        {
            if((1<<i)&a[left])
                seg[cur].bit[i]++;
        }
        seg[cur].sum=a[left];
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    seg[cur].sum=seg[cur*2].sum+seg[cur*2+1].sum;
    for(ll i=0; i<=22; i++)
    {
        seg[cur].bit[i]=seg[cur*2].bit[i]+seg[cur*2+1].bit[i];
    }
}
void pushdown(ll cur,ll left,ll right)
{
    if(lazy[cur]!=0)
    {
        ll temp=lazy[cur];
        for(ll i=0; i<=22; i++)
        {
            if((1<<i)&temp)
            {
                seg[cur].sum-=seg[cur].bit[i]*(1<<i);
                seg[cur].sum+=(right+1-left-seg[cur].bit[i])*(1<<i);
                ll extra=seg[cur].bit[i];
                seg[cur].bit[i]=0;
                seg[cur].bit[i]=(right+1-left-extra);
            }
        }
        if(left!=right)
        {
            lazy[cur*2]^=lazy[cur];
            lazy[cur*2+1]^=lazy[cur];
        }
    }
    lazy[cur]=0;
}
void update(ll cur,ll left,ll right,ll l,ll r,ll val)
{
    if(lazy[cur]!=0)pushdown(cur,left,right);
    if(left>r||right<l)return;
    if(l<=left&&right<=r)
    {
        lazy[cur]^=val;
        pushdown(cur,left,right);
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,l,r,val);
    update(cur*2+1,mid+1,right,l,r,val);
    seg[cur].sum=seg[cur*2].sum+seg[cur*2+1].sum;
    for(ll i=0; i<=22; i++)
    {
        seg[cur].bit[i]=seg[cur*2].bit[i]+seg[cur*2+1].bit[i];
    }
}

ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(lazy[cur]!=0)pushdown(cur,left,right);
    if(left>r||right<l)return 0;
    if(l<=left&&right<=r)
    {
        return seg[cur].sum;
    }
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return (x+y);
}
int main()
{
    fast
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++)
        cin>>a[i];
    build(1,0,n-1);
    ll q;
    cin>>q;
    while(q--)
    {
        ll m,x,y,val;
        cin>>m;
        if(m==1)
        {
            cin>>x>>y;
            cout<<query(1,0,n-1,x-1,y-1)<<endl;
        }
        else
        {
            cin>>x>>y>>val;
            update(1,0,n-1,x-1,y-1,val);
        }
    }
    return 0;
}
