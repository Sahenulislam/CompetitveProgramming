#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const ll mxn=2e5+10;
ll a[mxn+10];
ll lazy[mxn*4];
struct node
{
    ll sum,presize,sufsize,pre,suf,sz;
} seg[mxn*4];
node root;

node marge(node left,node right)
{
    node boss;
    boss.sum=left.sum+right.sum;
    if(left.suf!=right.pre)
    {
        boss.sum-=(left.sufsize*(left.sufsize+1))/2;
        boss.sum-=(right.presize*(right.presize+1))/2;
        ll x=left.sufsize+right.presize;
        boss.sum+=(x*(x+1))/2;
        if(left.sz == left.presize)
        {
            left.presize += right.presize;
        }
        if(right.sz == right.sufsize)
        {
            right.sufsize += left.sufsize;
        }

    }
    boss.pre=left.pre;
    boss.suf=right.suf;
    boss.presize = left.presize;
    boss.sufsize = right.sufsize;
    boss.sz = left.sz + right.sz;
    return boss;
}
void PushDown(ll cur,ll left,ll right)
{
    if(lazy[cur]%2)
    {
        seg[cur].pre=seg[cur].pre^1LL;
        seg[cur].suf=seg[cur].suf^1LL;
        if(left!=right)
        {
            lazy[cur*2]+=lazy[cur];
            lazy[cur*2+1]+=lazy[cur];
        }
    }
    lazy[cur]=0;
}
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        seg[cur].sum=1LL;
        seg[cur].pre=a[left];
        seg[cur].suf=a[left];
        seg[cur].presize=seg[cur].sufsize=1LL;
        seg[cur].sz = 1;
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    seg[cur]=marge(seg[cur*2],seg[cur*2+1]);
}


void update(ll cur,ll left,ll right,ll l, ll r)
{
//    if(pos<left||right<pos)return;
//    if(pos<=left&&right<=pos)
//    {
//        seg[cur].sum=val;
//        seg[cur].pre=seg[cur].suf=seg[cur].ans=max((ll) 0,val);
//        return;
//    }
    if(lazy[cur]%2)PushDown(cur,left,right);
    if(l>right||left>r)return;
    if(l<=left&&r>=right)
    {
        lazy[cur]+=1;
        PushDown(cur,left,right);
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,l,r);
    update(cur*2+1,mid+1,right,l,r);
    seg[cur]=marge(seg[cur*2],seg[cur*2+1]);
}

node query(ll cur,ll left,ll right,ll l,ll r)
{

    if(lazy[cur]%2)PushDown(cur,left,right);
    if(l>right||left>r)return root;
    if(l<=left&&r>=right)
    {
        PushDown(cur,left,right);
        return seg[cur];
    }
    ll mid=(left+right)/2;
    node x=query(cur*2,left,mid,l,r);
    node y=query(cur*2+1,mid+1,right,l,r);
    return marge(x,y);
}
int main()
{
    fast
    ll n,k;
    cin>>n>>k;
    for(ll i=0; i<n; i++)
        cin>>a[i];
    root.sum=0;
    root.presize=0;
    root.sufsize=0;
    root.suf=0;
    root.pre=0;
    build(1,0,n-1);
    while(k--)
    {
        ll ty,pos,val;
        cin>>ty>>pos>>val;
        if(ty==1)
        {
            update(1,0,n-1,pos-1,val-1);
        }
        else
        {
            node temp=query(1,0,n-1,pos-1,val-1);
            cout<<temp.sum<<endl;
        }
    }
    return 0;
}
