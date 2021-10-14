#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mx=2e5;
ll a[mx+2];
ll st[4*mx];
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        st[cur]=a[left];
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    st[cur]=st[cur*2]+st[cur*2+1];
}

ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(l>right||r<left)return 0;
    if(left>=l&&right<=r)return st[cur];
    ll mid=(left+right)/2;
    ll a=query(cur*2,left,mid,l,r);
    ll b=query(cur*2+1,mid+1,right,l,r);
    return(a+b);
}
void update(ll cur,ll left,ll right,ll pos,ll val)
{
    if(left>pos||right<pos)return;
    if(left>=pos&&right<=pos)
    {
        st[cur]=val;
        a[pos]=val;
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,pos,val);
    update(cur*2+1,mid+1,right,pos,val);
    st[cur]=st[cur*2]+st[cur*2+1];
}
int main()
{
    ll n,m,x,y,ty;
    cin>>n>>m;
    for(ll i=0; i<n; i++)cin>>a[i];
    build(1,0,n-1);
    while(m--)
    {
        cin>>ty>>x>>y;
        if(ty==1)
        {
            x--;
            update(1,0,n-1,x,y);
        }
        else
        {
            x--,y--;
            cout<<query(1,0,n-1,x,y)<<endl;
        }
    }
    return 0;
}
