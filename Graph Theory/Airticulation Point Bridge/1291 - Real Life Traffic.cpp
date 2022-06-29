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
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
const ll mxn=2e4+10;
vector<ll>g[mxn+10];
ll Start[mxn+10],vi[mxn+10],colure[mxn+10],cl=0,Time=0,low[mxn+10];
stack<ll>Stack;
void dfs(ll u,ll pa=-1)
{
    //cout<<u<<endl;
    vi[u]=1;
    Start[u]=++Time;
    low[u]=Start[u];
    Stack.push(u);
    for(auto v:g[u])
    {
        if(vi[v]==0)
        {
            //cout<<u<<in<<v<<in<<low[u]<<endl;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=pa)
        {
            low[u]=min(low[u],Start[v]);
           // cout<<u<<in<<v<<in<<low[u]<<endl;
        }

    }
    //cout<<u<<in<<low[u]<<in<<Start[u]<<endl;
    if(low[u]==Start[u])
    {
        colure[u]=++cl;
        while(!Stack.empty())
        {
           // cout<<Stack.size()<<endl;
            colure[Stack.top()]=cl;
            if(Stack.top()==u)
            {
                Stack.pop();
                break;
            }
            Stack.pop();
        }
    }
}
ll degree[mxn+10];
void colurecheck(ll n)
{
    ll ans=0;
    for(ll u=0; u<n; u++)
    {
        for(auto v:g[u])
        {
            if(colure[u]!=colure[v])
            {
                degree[colure[u]]++;
                degree[colure[v]]++;
            }
        }
    }
    //cout<<cl<<endl;
    for(ll i=1; i<=cl; i++)
    {
        if(degree[i]==2)ans++;
    }
    cout<<(ans+1)/2<<endl;

}

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,m,u,v;
        cin>>n>>m;
        for(ll i=0; i<m; i++)
        {
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        cout<<"Case "<<tt++<<": ";
        dfs(0);
        colurecheck(n);
        for(ll i=0;i<=n+2;i++)
        {
            g[i].clear();
            vi[i]=0;
            low[i]=0;
            colure[i]=0;
            Start[i]=0;
            degree[i]=0;
        }
        cl=0,Time=0;


    }
    return 0;
}
