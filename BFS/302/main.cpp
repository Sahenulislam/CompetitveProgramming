#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define nl "\n"
#define siz(pir) (ll)pir.size()
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
const ll mxn=4e5+10;
vector<ll>g[mxn+10];

int main()
{
    //fast

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n+10];
        ll b[n+10];
        for(ll i=0; i<n; i++)

        {


            cin>>a[i];
        }
        for(ll i=0; i<n; i++)
        {
            cin>>b[i];
        }
        map<pair<ll,ll>,ll>mp;
        for(ll i=0; i<n; i++)
        {
            mp[ {a[i],b[i]}]++;
        }
        ll ans=0;
        set<ll>st;
        for(ll i=0; i<n; i++)
        {
            if(st.count(a[i]))continue;
            st.insert(a[i]);
            ll x=a[i];
            ll y=b[i];
            for(ll j=2; j<=n; j++)
            {
                ll s=x*j;
                y=s-b[i];
                ans+=mp[ {x,y}];
            }
            cout<<ans<<nl;
        }
        cout<<ans/2<<nl;
    }
    return 0;
}
