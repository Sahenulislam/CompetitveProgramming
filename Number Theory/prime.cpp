*******************Siv****************
const ll mxn=1e6;
vector<ll>prime;
ll isp[mxn+3];
void siv()
{
    for(ll i=0; i<=mxn; i++)isp[i]=0;
    for(ll i=4; i<=mxn; i+=2)isp[i]=1;
    isp[0] = isp[1] = 1;
    for(ll i=3; i*i<=mxn; i+=2)
    {
        if(isp[i]==0)
        {
            for(ll j=i*i; j<=mxn; j+=(i+i))
                isp[j]=1;
        }
    }
    prime.pb(2);
    for(ll i=3; i<=mxn; i+=2)
    {
        if(isp[i]==0)
            prime.pb(i);
    }
}

**************prime Factorization**********

void primeFactor(ll n)
{
    vector<ll>primefac;
    for(ll i=0; prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
                primefac.pb(prime[i]);
            }
        }
    }
    if(n!=1)
        primefac.pb(n);
    return primefac;
}

****************Count divisor**********

void SivOfDivisor()
{
    for(ll i=2; i<=1e7; i++)
    {
        for(ll j=i; j<=1e7; j+=i)
        {
            div[j]++;
        }
    }
}

*************Isert divisor**********

void SivOfDivisor()
{
    for(ll i=2; i<=1e5; i++)
    {
        for(ll j=i; j<=1e5; j+=i)
        {
            v[j].pb(i);
        }
    }
}

**************Number of divisor********

void NOD(ll n)
{
    ll nod=1;
    for(ll i=0; prime[i]*prime[i]<=n; i++)
    {
        ll cnt=1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
        }
        nod*=cnt;
    }
    if(n!=1)nod*=2;
    return nod;
}

***********Sum of Divisor**********

void SOD(ll n)
{
    ll ans=1;
    for(ll i=0; prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            ll temsum=1,p=1;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                primefac.pb(prime[i]);
                p*=prime[i];
                temsum+=p;
            }
            ans*=temsum;
        }
    }
    if(n!=1)
        ans*=(n+1);
    return ans;
}

**********Eluers Phi************

void EluersPhiSum()
{
    for(int i=2; i<=mxn; i++)
        phi[i] = i;
    for(int i =2; i<=mxn; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=mxn; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
    prephi[1]=0;
    for(ll i=2; i<=mxn; i++)
    {
        prephi[i]=prephi[i-1]+(phi[i]*phi[i]);
    }
}

**********Eluers Phi************

void Eluersphi(ll n)
{
    for(ll i=0; i<=mxn; i++)isp[i]=0;
    for(ll i=4; i<=mxn; i+=2)isp[i]=1;
    isp[0] = isp[1] = 1;
    for(ll i=3; i*i<=mxn; i+=2)
    {
        if(isp[i]==0)
        {
            for(ll j=i*i; j<=mxn; j+=(i+i))
                isp[j]=1;
        }
    }
    prime.pb(2);
    for(ll i=3; i<=mxn; i+=2)
    {
        if(isp[i]==0)
            prime.pb(i);
    }
    ll ans=n;
    for(ll i=0; prime[i]*prime[i]<=n&&i<prime.size(); i++)
    {
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                n/=prime[i];
            }
            ans/=prime[i];
            ans*=(prime[i]-1);
        }
    }
    if(n>1)
    {
        ans/=n;
        ans*=(n-1);
    }
    return ans;
}


***************Bit Masking*************

void BitMasking_InclusionExclusion(ll n)
{
    ll mask=1<<m;
    vector<pair<ll,ll>>v;
    for(ll i=1; i<mask; i++)
    {
        ll lcm=1,cnt=0;
        for(ll j=0; j<m; j++)
        {
            if(i&(1<<j))
            {
                cnt++;
                lcm=LCM(lcm,a[j]);
            }
        }
        v.pb({cnt,lcm});
    }
    ll ans=n;
    for(ll i=0; i<v.size(); i++)
    {
        if(v[i].first%2!=0)
            ans-=n/v[i].second;
        else
            ans+=n/v[i].second;
    }
}

