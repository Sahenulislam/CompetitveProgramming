#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printv(x) for(ll i=0;i<x.size();i++){if(i+1==x.size())cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define printa(x,n) for(ll i=0;i<n;i++){if(i+1==n)cout<<x[i]<<endl;else cout<<x[i]<<" ";}
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define INF        9223372036854775806
#define MINF       -9223372036854775806
#define eps          1e-8
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "

const ll mxn=20;
char ch[mxn+10][mxn+10];
ll level[mxn+10][mxn+10];
ll vi[mxn+10][mxn+10];
ll R[10]= {1,-1,0,0};
ll C[10]= {0,0,1,-1};
ll n;
ll bfs(ll x,ll y,char temp)
{
    //cout<<temp<<endl;
    vi[x][y]=1;
    level[x][y]=0;
    if(ch[x][y]==temp)
        return 0;
    ch[x][y]='.';
    queue<pair<ll,ll>>q;
    q.push({x,y});
    while(!q.empty())
    {
        pair<ll,ll>a=q.front();
        q.pop();
        for(ll i=0; i<4; i++)
        {
            ll r=a.first+R[i];
            ll c=a.second+C[i];
            if(0<=r&&r<n&&0<=c&&c<n&&ch[r][c]!='#'&&vi[r][c]==0)
            {
                if(ch[r][c]!='.'&&ch[r][c]!=temp)continue;
                level[r][c]=level[a.first][a.second]+1;
                vi[r][c]=1;
                q.push({r,c});
                if(ch[r][c]==temp){
                    //ch[r][c]='.';
                    return level[r][c];
                }
            }
        }
    }
    return -10000;
}
int main()
{
    //fast
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll k=0;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<n; j++)
            {
                cin>>ch[i][j];
                if(ch[i][j]>='A'&&ch[i][j]<='Z')
                    k++;
            }
        }
        ll ans=0;
        //cout<<k<<endl;
        for(ll c=0;c<k-1;c++)
        {
              char cht='A'+c;
              //cout<<cht<<endl;
              for(ll i=0;i<n;i++)
              {
                  for(ll j=0;j<n;j++)
                  {
                      memset(level,0,sizeof(level));
                      memset(vi,0,sizeof(vi));
                      if(ch[i][j]==cht)
                      {
                          //cout<<cht+1<<endl;
                          ans+=bfs(i,j,cht+1);
                          //cout<<ans<<endl;
                      }
                  }
              }
        }
        //cout<<ans<<endl;
        if(ans<0)
            cout<<"Case "<<tt++<<": Impossible"<<endl;
        else
            cout<<"Case "<<tt++<<": "<<ans<<endl;
        //cout<<"33"<<endl;

    }
    return 0;
}

