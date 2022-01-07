/*
   problem: LightOj_1080 Binary simulation
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mx=1e5;
ll seg[mx*4],lazy[mx*4],a[mx+4];
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        seg[cur]=a[left];
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    seg[cur]=seg[cur*2]+seg[cur*2+1];
}
void PushDown(ll cur,ll left,ll right)
{
    if(lazy[cur]%2)
    {
        seg[cur]=(right+1-left)-seg[cur];
        if(left!=right)
        {
            lazy[cur*2]+=lazy[cur];
            lazy[cur*2+1]+=lazy[cur];
        }
    }
    lazy[cur]=0;
}
void update(ll cur,ll left,ll right,ll l,ll r)
{
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
    seg[cur]=seg[cur*2]+seg[cur*2+1];
}
ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(lazy[cur]%2)PushDown(cur,left,right);
    if(l>right||left>r)return 0;
    if(l<=left&&r>=right)
    {
        PushDown(cur,left,right);
        return seg[cur];
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
        string s;
        cin>>s;
        ll n=s.size();
        for(ll i=0; i<n; i++)
        {
            a[i]=(s[i]-'0');
        }
        build(1,0,n-1);
        ll q;
        cin>>q;
        cout<<"Case "<<tt++<<":"<<endl;
        while(q--)
        {
            char ch;
            cin>>ch;
            ll i,j;
            if(ch=='I')
            {
                cin>>i>>j;
                i--,j--;
                update(1,0,n-1,i,j);
            }
            else
            {
                cin>>i;
                i--;
                cout<<query(1,0,n-1,i,i)<<endl;
            }
        }
        memset(seg,0,sizeof(seg));
        memset(lazy,0,sizeof(lazy));
        memset(a,0,sizeof(a));
    }
    return 0;
}
