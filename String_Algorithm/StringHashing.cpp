/*
  CSES: String Algorithms -> Finding Periods
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mxn=1e6;
const ll base = 1949313259;
const ll mod = 2117566807;
ll pw[mxn+5],iv[mxn+5],prehash[mxn+5];
ll big_mod(ll a,ll b)
{
    if(b==0)return 1;
    else if(b==1)return a;
    if(b%2==0)
    {
        ll tm=big_mod(a,b/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return ((a%mod)*(big_mod(a,b-1)%mod))%mod;
}

void Modulex()
{
    pw[0]=1;
    iv[0]=1;
    ll modinv = big_mod(base, mod - 2);
    for(ll i=1; i<mxn; i++)
    {
        pw[i]= pw[i - 1] * base % mod;
        iv[i]= iv[i - 1] * modinv % mod;
    }
}
void ComputeHash(string s)
{
    prehash[0]=0;
    for(ll i=0; i<s.size(); i++)
    {
        prehash[i+1]=(prehash[i]+s[i]*pw[i])%mod;
    }
}
ll CmpSubString(ll l,ll r)
{
    ll presub=(prehash[r]-prehash[l])*iv[l]%mod;
    if(presub<0)
        presub+=mod;
    return presub%mod;
}

int main()
{
    Modulex();
    string s;
    cin>>s;
    ComputeHash(s);
    ll len=s.size();
    vector<ll>ans;
    for(ll i=1; i<=len; i++)
    {
        ll f=0;
        ll extra=len%(i);
        if(extra!=0)
        {
            ll x=CmpSubString(0,extra);
            ll y=CmpSubString(len-extra,len);
            if(x!=y)
                continue;
        }
        ll gethash1=CmpSubString(0,i);
        for(ll j=i+i; j<=len; j+=i)
        {
            ll gethash2=CmpSubString(j-i,j);
            if(gethash2!=gethash1)
            {
                f=1;
                break;
            }
        }
        if(f==0)
            ans.push_back(i);
    }
    for(ll i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
