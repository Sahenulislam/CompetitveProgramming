#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct cmp
{
    bool operator()(const pair<ll,ll>&a,const pair<ll,ll>&b)
    const
    {
        ll x=a.second-a.first+1;
        ll y=b.second-b.first+1;
        if(x==y)return a.first<b.first;
        else return x>y;
    }
};
int main()
{
    //fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+4];
        set<pair<ll,ll>,cmp>st;
        st.insert({1,n});
        for(ll i=1; i<=n; i++)
        {
            pair<ll,ll> x=*st.begin();
            st.erase(st.begin());
            ll m=(x.first+x.second)/2;
            a[m]=i;
            st.insert({x.first,m-1});
            st.insert({m+1,x.second});
        }
        for(ll i=1;i<=n;i++)
            cout<<a[i]<<in;
        cout<<endl;
    }
    return 0;
}
