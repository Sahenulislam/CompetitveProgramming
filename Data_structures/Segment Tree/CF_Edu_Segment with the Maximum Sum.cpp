#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const ll mxn=1e5+10;
ll a[mxn+10];
struct node
{
    ll ans,sum,pre,suf;
} seg[mxn*4];
node root;

node marge(node left,node right)
{
    node boss;
    boss.sum=left.sum+right.sum;
    boss.pre=max(left.pre,(left.sum+right.pre));
    boss.suf=max(right.suf,(left.suf+right.sum));
    boss.ans=max(left.ans,right.ans);
    boss.ans=max(boss.ans,boss.sum);
    boss.ans=max(boss.ans,boss.suf);
    boss.ans=max(boss.ans,boss.pre);
    boss.ans=max(boss.ans,left.suf+right.pre);
    return boss;
}
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        seg[cur].sum=a[left];
        seg[cur].pre=seg[cur].suf=seg[cur].ans=max((ll) 0,a[left]);
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    seg[cur]=marge(seg[cur*2],seg[cur*2+1]);
}


void update(ll cur,ll left,ll right,ll pos,ll val)
{
    if(pos<left||right<pos)return;
    if(pos<=left&&right<=pos)
    {
        seg[cur].sum=val;
        seg[cur].pre=seg[cur].suf=seg[cur].ans=max((ll) 0,val);
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,pos,val);
    update(cur*2+1,mid+1,right,pos,val);
    seg[cur]=marge(seg[cur*2],seg[cur*2+1]);
}

node query(ll cur,ll left,ll right,ll l,ll r)
{
    if(r<left||right<l)return root;
    if(l<=left&&right<=r)
    {
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
    root.ans=0;
    root.pre=0;
    root.suf=0;
    build(1,0,n-1);
    node temp=query(1,0,n-1,0,n-1);
    cout<<temp.ans<<endl;
    while(k--)
    {
        ll pos,val;
        cin>>pos>>val;
        update(1,0,n-1,pos,val);
        node temp=query(1,0,n-1,0,n-1);
        cout<<temp.ans<<endl;
    }
    return 0;
}
