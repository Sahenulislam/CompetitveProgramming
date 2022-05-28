#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const ll mxn=1e6+1e6+10;
const ll base = 1949313259;
const ll mod = 2117566807;
ll pw[mxn+10],inv[mxn+10],prehash[mxn+10];
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

void Compute_PreHash(string s)
{
    pw[0]=pw[1]=1;
    inv[0]=inv[1]=1;
    ll modinv=big_mod(base,mod-2);
    for(ll i=2; i<=mxn; i++)
    {
        pw[i]=(pw[i-1]*base)%mod;
        inv[i]=(inv[i-1]*modinv)%mod;
    }
    prehash[0]=0;
    for(ll i=1; i<=s.size(); i++)
    {
        prehash[i]=(prehash[i-1]+((s[i-1]-'a'+1)*pw[i])%mod)%mod;
    }
}

ll GetHash(ll left,ll right)
{
    ll gethash=((prehash[right]-prehash[left-1])*inv[left])%mod;
    gethash%=mod;
    if(gethash<0)
        gethash+=mod;
    return gethash;
}

int main()
{
    fast
    string s;
    cin>>s;
    ll len=s.size();
    s+=s;
    Compute_PreHash(s);
    ll k=1;
    for(ll i=2; i<=len; i++)
    {
        ll left=i;
        ll right=i+len-1;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            if(GetHash(k,k+(mid-i))!=GetHash(i,mid))
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        if(s[k+(left-i)-1]>s[left-1])
            k=i;
    }
    for(ll i=k; i<k+len; i++)
        cout<<s[i-1];
    return 0;
}
