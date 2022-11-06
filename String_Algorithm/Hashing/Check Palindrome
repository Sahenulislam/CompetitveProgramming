#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const ll mxn=5e5+10;
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
    reverse(s.begin(),s.end());
    sufhash[0]=0;
    for(ll i=1; i<=s.size(); i++)
    {
        sufhash[i]=(sufhash[i-1]+(s[i-1]-'a'+1)*pw[i])%mod;
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

ll IsPalindrome(ll left,ll right,ll len)
{
    if(GetPreHash(left,right)==GetSufHash(len-right+1,len-left+1))
        return 1;
    else
        return 0;
}


int main()
{
    fast
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    Compute_PreHash_SufHash(s);
    for(ll i=1; i<=s.size()-m+1; i++)
    {
        if(IsPalindrome(i,i+m-1,n))
        {
            cout<<"Accept"<<endl;
            return 0;
        }
    }
    cout<<"Reject"<<endl;



    return 0;
}

