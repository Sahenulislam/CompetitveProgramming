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
        ll c[n+2][n+2];
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=i; j++)
            {
                if(j==0||j==i) c[i][j]=1;
                else c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
        cout<<c[n][r]<<endl;
    }
    return 0;
}

