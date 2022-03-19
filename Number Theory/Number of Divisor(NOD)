/*
    Number of divisor using seive
    Number of divisor NOD:

    30
    1*30
    2*15
    3*10
    5*6

    NOD = 8;

    using prime
    NOD = 2^2,3^2,5^2
    SO, NOD =2*2*2
            =8;



*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mx=1000005;
ll isp[mx+2];
vector<ll>prime;
void siv()
{
    for(ll i=4; i<=mx; i+=2)
    {
        isp[i]=1;
    }
    for(ll i=3; i*i<=mx; i+=2)
    {
        if(isp[i]==0)
        {
            for(ll j=i*i; j<=mx; j+=(i+i))
                isp[j]=1;
        }
    }
    prime.pb(2);
    for(ll i=3; i<=mx; i+=2)
        if(isp[i]==0)
            prime.pb(i);
}
int main()
{
    siv();
    ll t,tt=1;
    cin>>t;
    while (t--)
    {
        ll n,cnt=1,k;
        cin>>n;
        // NOD of divisor .. NOD
        for(ll i=0; prime[i]*prime[i]<=n&&i<prime.size(); i++)
        {
            k=1;
            if (n%prime[i]==0)
            {
                while(n%prime[i]==0)
                {
                    n/=prime[i];
                    k++;
                }
            }
            cnt*=k;
        }
        if(n>1)
            cnt*=2;
        cout<<"Case "<<tt++<<": "<<cnt<<endl;
    }
    return 0;
}
