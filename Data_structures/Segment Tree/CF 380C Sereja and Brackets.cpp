#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const ll mxn=1e6+10;
string a;
struct node
{
    ll pre=0,suf=0,bre=0;
} root;
node seg[mxn*4];

node marge(node left,node right)
{
    node boss;
    boss.bre=left.bre+right.bre;
    ll mn=min(left.pre,right.suf);
    boss.bre+=(mn*2);
    left.pre-=mn;
    right.suf-=mn;
    boss.pre=left.pre+right.pre;
    boss.suf=left.suf+right.suf;
    return boss;
}
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        if(a[left]=='(')
            seg[cur].pre++;
        else
            seg[cur].suf++;
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    seg[cur]=marge(seg[cur*2],seg[cur*2+1]);
}

node query(ll cur,ll left,ll right,ll l,ll r)
{
    if(left>r||right<l)return root;
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
    cin>>a;
    build(1,0,a.size()-1);
    ll q;
    cin>>q;
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        node ans=query(1,0,a.size()-1,x-1,y-1);
        cout<<ans.bre<<endl;
    }
    return 0;
}
