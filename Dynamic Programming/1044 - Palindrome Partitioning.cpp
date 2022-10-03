#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);


const ll mxn=1e3+10;
ll dp1[mxn+10][mxn+10];
ll dp2[mxn+10][mxn+10];
string s;

ll call1(ll i,ll j)
{
    if(i>=j)return 1;
    if(dp1[i][j]!=-1)return dp1[i][j];
    if(s[i]==s[j])
        return dp1[i][j]=call1(i+1,j-1);
   else
        return dp1[i][j]=0;
}

ll call2(ll i,ll j)
{
    if(i>=j)return 1;
    if(dp2[i][j]!=-1)return dp2[i][j];
    if(dp1[i][j]==1)return 1;
    ll mn=1e10;
    for(ll k=i; k<j; k++)
    {
    	if(dp1[i][k]==1)
        	mn=min(mn,1+call2(k+1,j));
    }
    return dp2[i][j]=mn;
}
int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        cin>>s;
        ll n=s.size();
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        for(ll i=0; i<n; i++)
        {
            for(ll j=i; j<n; j++)
            {
               dp1[i][j]=call1(i,j);
                // cout<<i<<" "<<j<<" "<<x<<"\n";
            }
        }
        cout<<"Case "<<tt++<<": "<<call2(0,n-1)<<endl;
    }
    return 0;
}

