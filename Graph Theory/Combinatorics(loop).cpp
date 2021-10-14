#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;

int main()
{
    ll n,r;
    while(cin>>n>>r)
    {
        if(n==0&&r==0)
            break;
        double res=1;
        if(n-r>r)
        {
            r=n-r;
            for(ll i=r+1; i<=n; i++)
            {
                res=(res*i)/(i-r);
            }
            cout<<int(res+.01)<<endl;
        }
        else
        {
            for(ll i=r+1; i<=n; i++)
            {
                res=(res*i)/(i-r);
            }
            cout<<int(res+.01)<<endl;
        }

    }
    return 0;
}

