#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
long long lcm(int a, int b)
{
    return (a / (__gcd(a, b))) * b;
}
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define endint "\n"
vector<pair<ll,ll>>v[100100];
ll visit[100100];
ll cost[100100];
void dijstra(ll u,ll n) // CSES Problem: Shortest Routes l
{
    visit[u]=1;
    ll a,m,mm,b;
    for(ll i=2;i<=n;i++)
    {
        cost[i]=1e18;
    }
    cost[1]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push({cost[u],u});
    while(!q.empty())
    {
        a=q.top().second;
        b=q.top().first;
        q.pop();
        if(cost[a]<b)continue;
        for(auto i:v[a])
        {
            m=i.first;
            mm=i.second;
            if(cost[m]>b+mm)
            {
                cost[m]=b+mm;
                q.push({cost[m],m});
            }
        }
    }
}
int main()
{

    ll n,m,a,b,c;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        v[a].pb({b,c});
    }
    dijstra(1,n);
    for(ll i=1;i<=n;i++)
    {
        cout<<cost[i]<<in;
    }
     cout<<endl;
    return 0;
}

