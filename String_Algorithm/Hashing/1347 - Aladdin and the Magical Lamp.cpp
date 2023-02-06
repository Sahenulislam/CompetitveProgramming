#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const ll mxn=5010;
const ll base = 1949313259;
const ll mod = 2117566807;
ll prehash1[mxn+10];
ll prehash2[mxn+10];
ll prehash3[mxn+10];
ll pw[mxn+10],inv[mxn+10];

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

void powsystem()
{
    ll len=5002;
    pw[0]=pw[1]=1;
    inv[0]=inv[1]=1;
    ll inmod=big_mod(base,mod-2);
    for(ll i=2; i<=mxn; i++)
    {
        pw[i]=(pw[i-1]*base)%mod;
        inv[i]=(inv[i-1]*inmod)%mod;
    }
}
void Compute_PreHash_SufHash(string s1,string s2,string s3)
{

    prehash1[0]=0;
    for(ll i=1; i<=s1.size(); i++)
    {
        prehash1[i]=(prehash1[i-1]+(s1[i-1]-'a'+1)*pw[i])%mod;
    }
    prehash2[0]=0;
    for(ll i=1; i<=s2.size(); i++)
    {
        prehash2[i]=(prehash2[i-1]+(s2[i-1]-'a'+1)*pw[i])%mod;
    }
    prehash3[0]=0;
    for(ll i=1; i<=s3.size(); i++)
    {
        prehash3[i]=(prehash3[i-1]+(s3[i-1]-'a'+1)*pw[i])%mod;
    }

}

ll GetPreHash1(ll left,ll right)
{
    ll Hash=((prehash1[right]-prehash1[left-1])*inv[left])%mod;
    if(Hash<0)
        Hash+=mod;
    return Hash;

}
ll GetPreHash2(ll left,ll right)
{
    ll Hash=((prehash2[right]-prehash2[left-1])*inv[left])%mod;
    if(Hash<0)
        Hash+=mod;
    return Hash;
}
ll GetPreHash3(ll left,ll right)
{
    ll Hash=((prehash3[right]-prehash3[left-1])*inv[left])%mod;
    if(Hash<0)
        Hash+=mod;
    return Hash;
}


int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    powsystem();
    while(t--)
    {
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        Compute_PreHash_SufHash(s1,s2,s3);
        ll left=1;
        ll right=min({s1.size(),s2.size(),s3.size()});
        ll ans=0;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            set<ll>st1,st2,st3;
            ll f=0;
            for(ll i=0; i<=s1.size()-mid; i++)
            {
                st1.insert(GetPreHash1(i+1,i+mid));
            }
            for(ll i=0; i<=s2.size()-mid; i++)
            {
                st2.insert(GetPreHash2(i+1,i+mid));
            }
            for(ll i=0; i<=s3.size()-mid; i++)
            {
                st3.insert(GetPreHash3(i+1,i+mid));
            }
            for(auto x:st1)
            {
                if(st2.count(x)&&st3.count(x))
                    f=1;
            }
            if(f)
            {
                left=mid+1;
                ans=max(ans,mid);
            }
            else
                right=mid-1;
        }
        cout<<"Case "<<tt++<<": "<<ans<<nl;
    }
    return 0;
}
