#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

ll dp[14][2];
string s;
ll x;
ll recur(ll i,ll flag)
{
    if(i==x)return 1;
    if(dp[i][flag]!=-1)return dp[i][flag];
    ll res=0;
    if(flag==0)
    {
        for(ll j=0; j<=(s[i]-'0'); j++)
        {
            if(j==4)continue;
            if(j==s[i]-'0')
                res+=recur(i+1,0LL);
            else
                res+=recur(i+1,1LL);
        }
    }
    else
    {

        for(ll j=0; j<=9; j++)
        {
            if(j==4)continue;
            res+=recur(i+1,1LL);
        }
    }
    return dp[i][flag]=res;

}

int main()
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll left=0;
        ll right=1e13;
        ll mn=1e18;
        while(left<=right)
        {
            memset(dp,-1,sizeof(dp));
            ll mid=(left+right)/2;
            s=to_string(mid);
            x=s.size();
            ll ans=recur(0,0)-1;
            if(ans<n)
            {
                left=mid+1;
            }
            else if(ans>=n)
            {
                right=mid-1;
                mn=min(mn,mid);
            }
        }
        cout<<mn<<"\n";
    }
    return 0;
}
