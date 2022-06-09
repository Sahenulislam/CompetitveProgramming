#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
const ll mxn=110;
ll vist[mxn+10][mxn+10],level[mxn+10][mxn+10];
ll a[mxn+10][mxn+10];
ll C[10]= {1,1,2,2,-1,-1,-2,-2};
ll R[10]= {2,-2,1,-1,2,-2,1,-1};
ll n,m,cnt,org;
ll bfs(ll i,ll j)
{
    if(a[i][j]!=0)cnt++;
    ll ans=0;
    level[i][j]=0;
    vist[i][j]=1;
    queue<pair<ll,ll>>q;
    q.push({i,j});
    while(!q.empty())
    {
        i=q.front().first;
        j=q.front().second;
        q.pop();
        for(ll k=0; k<8; k++)
        {
            ll r=i+R[k];
            ll c=j+C[k];
            if(vist[r][c]==0&&r>=1&&r<=n&&c>=1&&c<=m)
            {
                vist[r][c]=1;
                q.push({r,c});
                level[r][c]=level[i][j]+1;
                if(a[r][c]==0)continue;
                cnt++;
                ans+=(level[r][c]+a[r][c]-1)/a[r][c];
            }
        }
    }
    return ans;
}
int main()
{
    fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        org=0;
        char x;
        cin>>n>>m;
        memset(a,0,sizeof(a));
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=m; j++)
            {
                cin>>x;
                if(x-'0'>=1&&x-'0'<=9)
                {
                    org++;
                    a[i][j]=x-'0';
                }
                else
                    a[i][j]=0;
            }
        }
        ll ans=INF;
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=m; j++)
            {
                memset(vist,0,sizeof(vist));
                memset(level,0,sizeof(level));
                cnt=0;
                ll temp=bfs(i,j);
                if(cnt==org)
                    ans=min(ans,temp);
            }
        }
        cout<<"Case "<<tt++<<": ";
        if(ans==INF)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}

