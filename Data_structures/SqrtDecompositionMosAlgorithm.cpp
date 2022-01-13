#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=1e5;
ll a[mxn+5],freq[mxn+5]= {0},ans[mxn+5],sqt,cnt=0;
struct query
{
    ll idx,l,r;
};
query Q[mxn+5];

ll cmp(query & a, query &b)
{
    ll x=a.l/sqt;
    ll y=b.l/sqt;
    if(x!=y)
        return a.l<b.l;
    else
        return a.r<b.r;
};

void add(ll pos)
{
    freq[a[pos]]++;
    if(freq[a[pos]]==1)cnt++;
}

void removed(ll pos)
{
    freq[a[pos]]--;
    if(freq[a[pos]]==0)cnt--;
}

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,q,x,y;
        cin>>n>>q;
        sqt=sqrt(n);
        for(ll i=0; i<n; i++)
            cin>>a[i];
        for(ll i=0; i<q; i++)
        {
            cin>>x>>y;
            Q[i].l=x;
            Q[i].r=y;
            Q[i].idx=i;
        }
        sort(Q,Q+q,cmp);
        ll left=0,right=-1;
        for(ll i=0; i<q; i++)
        {
            ll L=Q[i].l;
            ll R=Q[i].r;
            L--,R--;
            while(left<L)
                removed(left++);
            while(left>L)
                add(--left);
            while(right<R)
                add(right++);
            while(right>R)
                removed(--right);
            ans[Q[i].idx]=cnt;
        }
        cout<<"Case "<<tt++<<":"<<endl;
        for(ll i=0; i<q; i++)
        {
            cout<<ans[i]<<endl;
        }
        memset(a,0,sizeof(a));
        memset(freq,0,sizeof(a));
        memset(ans,0,sizeof(a));
        cnt=0;
    }
    return 0;
}

