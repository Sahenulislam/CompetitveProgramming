*******************BFS*****************

void bfs(int u)
{
    visit[u]=1;
    queue<ll>q;
    q.push(u);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(auto i:g[u])
        {
            ll v=v[u][i];
            if(visit[v]==0)
            {
                visit[v]=1;
                q.push(v);
            }
        }
    }
}


*****************grid BFS******************

ll R[5]= {0,1,-1,0,-1,1,1,-1};
ll C[5]= {1,0,0,-1,1,1,-1,-1};
void bfs(ll i,ll j)
{
    ll rr,cc,a,b;
    visit[i][j]=1;
    queue<pair<ll,ll>>q;
    q.push({i,j});
    while(!q.empty())
    {
        a=q.front().first;
        b=q.front().second;
        q.pop();
        for(ll i=0; i<4; i++)
        {
            rr=a+R[i];
            cc=b+C[i];
            if(rr>=0&&rr<n&&cc>=0&&cc<m&&v[rr][cc]==1&&visit[rr][cc]==0)
            {
                q.push({rr,cc});
                visit[rr][cc]=1;
            }
        }
    }
}

********** Variation of DFS Cycle Undirected Graph ************

void dfs(ll u,ll p)
{
    colur[u]=1;
    for(auto v: g[u])
    {
        if(colur[v]==0&&f==0)
        {
            pa[v]=u;
            dfs(v,u);
        }
        else if(v!=p&&f==0)
        {
            //cout<<u<<in<<v<<endl;
            st_city=u;
            en_city=v;
            f=1;
        }
    }
    colur[u]=2;
}

void cycle_print()
{
    cycle.pb(en_city);
    while(st_city!=en_city)
    {
        // cout<<st_city<<endl;
        cycle.pb(st_city);
        st_city=pa[st_city];
    }
    cycle.pb(en_city);
}


*********** Variation of DFS Cycle Directed Graph **************

void dfs(ll u,ll p)
{
    colur[u]=1;
    for(auto v: g[u])
    {
        if(colur[v]==0&&f==0)
        {
            pa[v]=u;
            dfs(v,u);
        }
        else if(colur[v]==1&&f==0)
        {
            st_city=u;
            en_city=v;
            f=1;
        }
    }
    colur[u]=2;
}

void cycle_print()
{
    cycle.pb(en_city);
    while(st_city!=en_city)
    {
        cycle.pb(st_city);
        st_city=pa[st_city];
    }
    cycle.pb(en_city);
    reverse(cycle.begin(),cycle.end());
}

*********** Variation of DFS Topological Sort *************

void dfs(ll u)
{
    visit[u]=1;
    for(auto v: g[u])
    {
        if(visit[v]==0)
            dfs(v);
        else if(vi[v]==1)
            f=1;
    }
    visit[u]=2;
    ve.pb(u);
}

*************** Dijstra **********************

void dijstra(ll u,ll n)
{
    for(ll i=1; i<=n; i++)
        cost[i]=1e18;
    cost[1]=0;
    priority_queue<pair<ll,ll>>q;
    q.push({-cost[u],u});
    while(!q.empty())
    {
        ll wt=-q.top().first;
        ll u=q.top().second;
        q.pop();
        if(cost[u]<wt)continue;
        for(auto i:g[u])
        {
            ll v=i.first;
            ll wtt=i.second;
            if(cost[v]>wtt+wt)
            {
                cost[v]=wt+wtt;
                q.push({-cost[v],v});
            }
        }
    }
}

********* Variation Dijstra kth Sortest path ****************
// maximum k=10;
void dijstra(ll n,ll k)
{
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<k; j++)
        {
            if(i==1)
            {
                cost[i][j]=0;
            }
            cost[i][j]=INF;
        }

    }
    priority_queue<pair<ll,ll>>q;
    q.push({0,1});
    while(!q.empty())
    {
        ll wt=-q.top().first;
        ll u=q.top().second;
        q.pop();
        if(cost[u][k-1]<wt)continue;
        for(auto i:g[u])
        {
            ll wtch=i.second;
            ll v=i.first;
            if(wt+wtch<cost[v][k-1])
            {
                cost[v][k-1]=wt+wtch;
                q.push({-cost[v][k-1],v});
                sort(cost[v],cost[v]+k);
            }
        }
    }
}

****************** Variation of Dijsta Topological Sort **************
void toplogical_sort(ll n)
{
    vector<ll>vv;
    queue<ll>q;
    for(ll i=1; i<=n; i++)
    {
        if(cost[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        ll a=q.front();
        q.pop();
        vv.pb(a);
        for(ll i=0; i<v[a].size(); i++)
        {
            ll m=v[a][i];
            cost[m]--;
            if(cost[m]==0)
            {
                q.push(m);
            }
        }
    }
    if(vv.size()==n)
    {
        for(ll i=0; i<vv.size(); i++)cout<<vv[i]<<in;
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
}
int main()
{
    ll n,m,a,b;
    cin>>n>>m;
    for(ll i=0; i<m; i++)
    {
        cin>>a>>b;
        v[a].pb(b);
        cost[b]++;
    }
    toplogical_sort(n);
    return 0;
}

************************ Variation Dijstra ***********************
/*
    >> what is the minimum price of such a route?
    >> how many minimum-price routes are there? (modulo 109+7)
    >> what is the minimum number of flights in a minimum-price route?
    >> what is the maximum number of flights in a minimum-price route?
*/

vector<pair<ll,ll>>g[mxn+3];
ll cost[mxn+3],FlightMx[mxn+3],FlightMn[mxn+3],FlightRoute[mxn+3];
void dijstra(ll n)
{
    for(ll i=1; i<=n+5; i++)
    {
        cost[i]=INF;
        FlightRoute[i]=1;
    }
    cost[1]=0;
    priority_queue<pair<ll,ll>>q;
    q.push({-0,1});
    while(!q.empty())
    {
        ll wtp=-q.top().first;   //wtp  weight of parent
        ll u=q.top().second;
        q.pop();
        if(cost[u]<wtp)
            continue;
        for(auto ch:g[u])
        {
            ll wtch=ch.second;   //wtch  weight of child
            ll v=ch.first;
            if(wtch+wtp==cost[v])
            {
                cost[v]=wtch+wtp;
                FlightRoute[v]+=FlightRoute[u];
                FlightRoute[v]%=mod;
                FlightMx[v]=max(FlightMx[v],FlightMx[u]+1);
                FlightMn[v]=min(FlightMn[v],FlightMn[u]+1);
            }
            else if(wtch+wtp<cost[v])
            {
                cost[v]=wtch+wtp;
                FlightRoute[v]=FlightRoute[u];
                FlightRoute[v]%=mod;
                FlightMx[v]=FlightMx[u]+1;
                FlightMn[v]=FlightMn[u]+1;
                q.push({-cost[v],v});
            }
        }
    }
}

******************* Floyad Warshal *****************

void Floyad_warshal(ll u,ll n)
{
    for(ll k=1; k<=n; k++)
    {
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }
}

************* Bellmand Ford and Negetive Cycle print **************

struct edge
{
    ll a, b, wet;
} g[mxn];

void bellmand(ll n, ll m)
{
    ll cost[mxn];
    for (ll i = 1; i <= n; i++)
        cost[i] = 1e18;
    ll pa[mxn], f;
    for (ll i = 0; i <= n; i++)
    {
        f = -1;
        for (ll j = 0; j < m; j++)
        {
            if (cost[g[j].a] + g[j].wet < cost[g[j].b])
            {
                f = g[j].b;
                pa[g[j].b] = g[j].a;
                cost[g[j].b] = cost[g[j].a] + g[j].wet;
            }
        }
    }
    if (f == -1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        ll y = pa[f];
        for (ll i = 0; i < n; i++)
        {
            y = pa[y];
        }
        vector<ll> ans;
        ans.push_back(y);
        ll x=y;
        while (1)
        {
            if (ans.size() > 1 && y == pa[x])
                break;
            x = pa[x];
            ans.push_back(x);
        }
        ans.push_back(y);
        reverse(ans.begin(),ans.end());
        for (ll i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}

**************** Minimum Spaning Tree *******************

void make_set(ll n)
{
    for (ll i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
}

ll find(ll x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}

ll unio(ll u, ll v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return 0;
    else
    {
        parent[u] = v;
        return 1;
    }
}

void MST() // Minimum Spaning Tree
{
    sort(g.begin(),g.end());  // sort on weight
    for (ll i = 0; i < g.size(); i++)
    {
        ll u = g[i].second.first;
        ll v = g[i].second.second;
        ll cost = g[i].first;

        if (unio(u, v))
        {
            st.insert(u);
            st.insert(v);
            ans += cost;
        }
    }
}

************ Articulation point / bridge ********
#include <bits/stdc++.h>
using namespace std ;

#define mxN 10000000

vector <int> G[mxN + 5] ;
vector < pair<int, int> > bridges ;
bool vis[mxN + 5] ;
int tin[mxN + 5] ;
int low[mxN + 5] ;
int timer ;

void graph_clear(int n)
{
    for (int i = 0; i < n ; ++i)
    {
        G[i].clear() ;
    }
    bridges.clear() ;
}
void is_bridge(int u, int v)
{
    int x = min(u, v) ;
    int y = max(u, v) ;
    bridges.push_back(make_pair(x, y)) ;
}
void dfs(int u, int p = -1 )
{
    vis[u] = 1 ;
    tin[u] = low[u] = timer++ ;
    for(int v : G[u])
    {
        if(v == p)
            continue ;
        if(vis[v])
        {
            low[u] = min(low[u], tin[v]) ;
        }
        else
        {
            dfs(v, u) ;
            low[u] = min(low[u], low[v]) ;
            if(low[v] > tin[u])
            {
                is_bridge(u, v) ;
            }
        }
    }
}
void find_bridges(int nodes)
{
    timer = 0 ;
    for(int i = 0 ; i <= nodes ; i++)
    {
        vis[i] = 0 ;
        tin[i] = low[i] = -1 ;
    }
    for(int i = 0 ; i < nodes ; i++)
    {
        if(!vis[i])
            dfs(i) ;
    }
    sort(bridges.begin(), bridges.end()) ;
    cout << bridges.size() << " critical links\n" ;
    if(bridges.size() == 0)
        return ;
    for(auto it : bridges)
    {
        cout << it.first << " - " << it.second << "\n" ;
    }
    cout << "\n" ;
}
int main()
{
    int n ;
    while(cin >> n)
    {
        for(int i = 0 ; i < n ; i++)
        {
            int u ;
            cin >> u ;
            char ch ;
            cin >> ch ;
            int x ;
            cin >> x ;
            cin >> ch ;
            for(int j = 0 ; j < x ; j++)
            {
                int v ;
                cin >> v ;
                G[u].push_back(v) ;
            }
        }
        find_bridges(n) ;
        graph_clear(n) ;
    }
    return 0 ;
}


