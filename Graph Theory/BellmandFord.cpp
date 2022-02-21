#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxn = 6000;
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
        for (ll j = 0; j < m; j++)
        {
            if (cost[g[j].a] + g[j].wet < cost[g[j].b])
            {
                cost[g[j].b] = cost[g[j].a] + g[j].wet;
            }
        }
    }
}
int main()
{
    ll n, m, x, y, wt;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        cin >> x >> y >> wt;
        g[i].a = x;
        g[i].b = y;
        g[i].wet = wt;
    }
    bellmand(n, m);
}


/*

  **Finding Negative Cycle And Print Cycle
  **CSES problem: Cycle Finding

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 6000;
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
        cout << "NO negative Cycle" << endl;
    else
    {
        cout << "Negative cycle Found" << endl;
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
int main()
{
    ll n, m, x, y, wt;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        cin >> x >> y >> wt;
        g[i].a = x;
        g[i].b = y;
        g[i].wet = wt;
    }
    bellmand(n, m);
}


