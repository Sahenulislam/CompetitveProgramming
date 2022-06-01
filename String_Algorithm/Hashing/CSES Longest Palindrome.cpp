#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const ll mxn=1e6+10;
const ll base = 1949313259;
const ll mod = 2117566807;
ll prehash[mxn+10],sufhash[mxn+10],pw[mxn+10],inv[mxn+10];

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

void Compute_PreHash_SufHash(string s)
{
    ll len=s.size();
    pw[0]=pw[1]=1;
    inv[0]=inv[1]=1;
    ll inmod=big_mod(base,mod-2);
    for(ll i=2; i<=mxn; i++)
    {
        pw[i]=(pw[i-1]*base)%mod;
        inv[i]=(inv[i-1]*inmod)%mod;
    }
    prehash[0]=0;
    for(ll i=1; i<=s.size(); i++)
    {
        prehash[i]=(prehash[i-1]+(s[i-1]-'a'+1)*pw[i])%mod;
    }
    sufhash[0]=0;
    for(ll i=s.size(); i>=1; i--)
    {
        sufhash[len+1-i]=(sufhash[len-i]+(s[i-1]-'a'+1)*pw[len+1-i])%mod;
    }
}

ll GetPreHash(ll left,ll right)
{
    ll Hash=((prehash[right]-prehash[left-1])*inv[left])%mod;
    if(Hash<0)
        Hash+=mod;
    return Hash;

}
ll GetSufHash(ll left,ll right)
{
    ll Hash=((sufhash[right]-sufhash[left-1])*inv[left])%mod;
    if(Hash<0)
        Hash+=mod;
    return Hash;

}


int main()
{
    fast
    string s;
    cin>>s;
    ll len=s.size();
    Compute_PreHash_SufHash(s);
    ll leftans=1;
    ll rightans=1;
    for(ll i=1; i<=len; i++)
    {
        ll left=i;
        ll right=min(len-left,left-1)+left;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            if(GetPreHash(i,mid)==GetSufHash(len+1-i,len+1-i+(mid-i)))
            {
                if(abs(leftans-rightans)<abs(mid-(i-(mid-i))))
                {
                    leftans=i-(mid-i);
                    rightans=mid;
                }
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        left=i;
        right=min(len+1-left,left-1)+left;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            if(GetPreHash(i,mid)==GetSufHash(len+2-i,len+2-i+(mid-i))&&len+2-i>0&&len+2-i+(mid-i)<=len)
            {
                if(abs(leftans-rightans)<abs(mid-(i-(mid-i+1))))
                {
                    leftans=i-(mid-i+1);
                    rightans=mid;
                }
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

    }
    for(ll i=leftans; i<=rightans; i++)
        cout<<s[i-1];
    cout<<endl;


    return 0;
}


