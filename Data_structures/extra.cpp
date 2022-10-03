*********** tamplate *********
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define endl "\n"
const ll mod=1e9+7;
const double pi=2*acos(0.0);
ll lcm(ll a,ll b)
{
    return (a/(__gcd(a, b)))*b;
}
ll big_mod(ll a,ll b)
{
    if(b==0)return 1;
    else if(b==1)return a;
    if(b%2==0)
    {
        ll tm=big_mod(a,b/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return ((a%mod)*(big_mod(a,b-1)%mod))%mod;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
    }
    return 0;
}


************* Euler Tour on Tree **************
/*

>> problem 1:
    two types query:
    1. change the value of node s to x
    2. calculate the sum of values in the subtree of node s

    same Variation for
    > maximum weight
    > minimum weight
    > XOR
    > GCD

>> problem 2:
    find whether U is the same subtree rooted v.
>> problem 3:


*/
const ll mxn=2e5;
vector<ll>g[mxn+3];
ll sttime[mxn+3],fintime[mxn+3],a[mxn+3],st[mxn*4],valu[mxn+3];
ll tim=0;
ll vist[mxn+3];
void dfs(ll u)
{
    sttime[u]=++tim;
    vist[u]=1;
    for(auto v:g[u])
    {
        if(!vist[v])
            dfs(v);
    }
    fintime[u]=tim;
}
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        st[cur]=valu[a[left]];
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    st[cur]=st[cur*2]+st[cur*2+1];
}
void update(ll cur,ll left,ll right,ll pos,ll val)
{
    if(pos<left||pos>right)return;
    if(pos<=left&&pos>=right)
    {
        st[cur]=val;
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,pos,val);
    update(cur*2+1,mid+1,right,pos,val);
    st[cur]=st[cur*2]+st[cur*2+1];
}
ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(r<left||l>right)return 0;
    if(l<=left&&r>=right)
    {
        return st[cur];
    }
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return (x+y);
}
int main()
{
    ll n,q;
    cin>>n>>q;
    ll u,v;
    for(ll i=1; i<=n; i++)
    {
        cin>>valu[i];
    }
    for(ll i=1; i<=n-1; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);

    }
    dfs(1);
    vector<pair<ll,ll>>ve;
    for(ll i=1; i<=n; i++)
    {
        ve.push_back({sttime[i],i});
    }
    sort(ve.begin(),ve.end());
    for(ll i=0; i<ve.size(); i++)
    {
        a[ve[i].first]=ve[i].second;
    }
    build(1,1,n);
    while(q--)
    {
        ll x;
        cin>>x;
        if(x==1)
        {
            ll val;
            cin>>u>>val;
            ll atime=sttime[u];
            update(1,1,n,atime,val);
        }
        else
        {
            ll d;
            cin>>d;
            ll x=sttime[d];
            ll y=fintime[d];
            ll ans=query(1,1,n,x,y);
            cout<<ans<<endl;
        }
    }
    return 0;
}



/*
   problem:
      two types query:
    1. change the value of node s to x
    2. calculate distance between node U to V.

    same variation XOR
*/

#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll mxn=3*10e4;
ll sttime[mxn+3],fintime[mxn+3],vist1[mxn+3],valu[mxn*2+4],a[mxn*2+4];
vector<ll>g[mxn+4];
ll tim=0;
void dfs_for_timeing(ll u)
{
    vist1[u]=1;
    sttime[u]=++tim;
    for(auto v:g[u])
    {
        if(!vist1[v])
        {
            dfs_for_timeing(v);
        }
    }
    fintime[u]=++tim;
}

ll st[mxn*4];
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        st[cur]=valu[a[left]];
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    st[cur]=st[cur*2]+st[cur*2+1];
}
void update(ll cur,ll left,ll right,ll pos,ll val)
{
    if(pos<left||pos>right)return;
    if(pos<=left&&pos>=right)
    {
        st[cur]=val;
        valu[a[pos]]=val;
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,pos,val);
    update(cur*2+1,mid+1,right,pos,val);
    st[cur]=st[cur*2]+st[cur*2+1];
}
ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(r<left||l>right)return 0;
    if(l<=left&&r>=right)
    {
        return st[cur];
    }
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return (x+y);
}


ll vist2[mxn+3],sptb[mxn+3][30],level[mxn+3],pa[mxn+3];
void dfs_for_parent(ll u)
{
    vist2[u]=1;
    for(auto v:g[u])
    {
        if(!vist2[v])
        {
            level[v]=level[u]+1;
            pa[v]=u;
            dfs_for_parent(v);
        }
    }
}

ll sparsetable(ll n)
{
    memset(sptb,-1,sizeof(sptb));
    for(ll i=0; i<n; i++)
    {
        sptb[i][0]=pa[i];
    }
    for(ll i=1; (1<<i)<=n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            sptb[j][i]=sptb[sptb[j][i-1]][i-1];
        }
    }
}
ll lca(ll u,ll v)
{
    if(level[u]<level[v])
        swap(u,v);
    ll log=log2(level[u]);
    for(ll i=log; i>=0; i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            u=sptb[u][i];
        }
    }
    if(u==v)return u;
    for(ll i=log; i>=0; i--)
    {
        if(sptb[u][i]!=sptb[v][i])
        {
            u=sptb[u][i];
            v=sptb[v][i];
        }
    }
    return pa[u];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll u,v;
        for(ll i=0; i<n; i++)
        {
            cin>>valu[i];
        }
        for(ll i=0; i<n-1; i++)
        {
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs_for_timeing(0);
        vector<pair<ll,ll>>ve;
        for(ll i=0; i<n; i++)
        {
            ve.push_back({sttime[i],i});
        }
        for(ll i=0; i<n; i++)
        {
            ve.push_back({fintime[i],-i});
        }
        sort(ve.begin(),ve.end());
        a[ve[0].first]=ve[0].second;
        for(ll i=1; i<ve.size(); i++)
        {
            if(ve[i].second<=0)
            {
                ll temp=-ve[i].second;
                a[ve[i].first]=n+temp;
                valu[n+temp]=-valu[temp];
            }
            else
            {
                a[ve[i].first]=ve[i].second;
            }
        }
        build(1,1,n*2);
        level[0]=0;
        pa[0]=1;
        dfs_for_parent(0);
        sparsetable(n);
        ll q;
        cin>>q;
        cout<<"Case "<<tt++<<": "<<endl;
        while(q--)
        {
            ll x,ans;
            cin>>x;
            if(x==1)
            {
                ll pos,val;
                cin>>pos>>val;
                ll timestart=sttime[pos];
                ll timeend=fintime[pos];
                update(1,1,n*2,timestart,val);
                update(1,1,n*2,timeend,-val);
            }
            else
            {
                ll u,v;
                cin>>u>>v;
                ll lc=lca(u,v);
                if(lc==u||lc==v)
                {
                    //cout<<lc<<" "<<sttime[lc]<<" "<<sttime[u]<<" "<<sttime[v]<<endl;
                    if(lc==u)
                    {
                        ans=query(1,1,n*2,sttime[lc],sttime[v]);
                    }
                    else
                    {
                        ans=query(1,1,n*2,sttime[lc],sttime[u]);
                    }
                }
                else
                {
                    ans=query(1,1,n*2,sttime[lc],sttime[u])+query(1,1,n*2,sttime[lc],sttime[v])-valu[lc];
                }
                cout<<ans<<endl;
            }
        }
        for(ll i=0; i<=mxn; i++)
        {
            tim=0;
            level[i]=0;
            pa[i]=0;
            g[i].clear();
            vist1[i]=0;
            vist2[i]=0;
            sttime[i]=0;
            fintime[i]=0;
        }
        memset(st,0,sizeof(st));
        memset(a,0,sizeof(a));
        memset(valu,0,sizeof(valu));
    }
    return 0;
}

***************** sparse table ****************
int main()
{
    ll n,q;
    cin>>n>>q;
    ll c[n+10];
    for(ll i=0; i<n; i++)
        cin>>c[i];
    ll k=log2(n);
    ll sps_tb[k+10][n+10];
    for(ll i=0; i<n; i++)
    {
        sps_tb[0][i]=c[i];
    }
    for(ll i=1; i<=k; i++)
    {
        for(ll j=0; j+(1<<i-1)<=n; j++)
        {
            sps_tb[i][j]=min(sps_tb[i-1][j],sps_tb[i-1][j+(1<<i-1)]);
        }
    }
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        a--,b--;
        ll m=log2(b-a+1);
        cout<<min(sps_tb[m][a],sps_tb[m][b-(1<<m)+1])<<endl;
    }
    return 0;
}

*********** combinatorics **********
ll mod=1e9+7;

ll big_mod(ll a,ll b)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll tm=big_mod(a,b/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return ((a%mod)*(big_mod(a,b-1)%mod))%mod;
}

const ll mx=1e6+1;
ll fac[mx];
void factorial()
{
    fac[0]=1;
    for(ll i=1; i<=1e6; i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
}

ll ncr(ll n,ll r)
{
    return (fac[n]*((big_mod(fac[n-r],mod-2)*big_mod(fac[r],mod-2))%mod))%mod;
}

int main()
{
    factorial();
    ll n,r,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        cout<<ncr(n,r)<<endl;
    }
    return 0;
}

********** String Hashing *********

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

const ll mxn=2e5+10;
const ll base = 1949313259;
const ll mod = 2117566807;
ll prehash[mxn+10],sufhash[mxn+10],pw[mxn+10],inv[mxn+10];

ll big_mod(ll a,ll b)
{
    if(b==0)return 1;
    else if(b==1)return a;
    if(b%2==0)
    {
        ll tm=big_mod(a,b/2);
        return ((tm%mod)*(tm%mod))%mod;
    }
    else return ((a%mod)*(big_mod(a,b-1)%mod))%mod;
}

void Compute_PreHash_SufHash(string s)
{
    ll len=s.size();
    pw[0]=pw[1]=1;
    inv[0]=inv[1]=1;
    ll inmod=big_mod(base,mod-2);
    for(ll i=2;i<=mxn;i++)
    {
        pw[i]=(pw[i-1]*base)%mod;
        inv[i]=(inv[i-1]*inmod)%mod;
    }
    prehash[0]=0;
    for(ll i=1;i<=s.size();i++)
    {
        prehash[i]=(prehash[i-1]+(s[i-1]-'a'+1)*pw[i])%mod;
    }
    sufhash[0]=0;
    for(ll i=s.size();i>=1;i--)
    {
        sufhash[len+1-i]=(sufhash[len-i]+(s[i-1]-'a'+1)*pw[len+1-i])%mod;
    }
}

ll GetPreHash(ll left,ll right)
{
    ll Hash=((prehash[right]-prehash[left-1])*inv[left])%mod;
    if(Hash<0)
        Hash+=mod;
    return Hash;

}
ll GetSufHash(ll left,ll right)
{
    ll Hash=((sufhash[right]-sufhash[left-1])*inv[left])%mod;
    if(Hash<0)
        Hash+=mod;
    return Hash;

}


int main()
{
    string s;
    cin>>s;
    ll len=s.size();
    Compute_PreHash_SufHash(s);
    ll q;
    cin>>q;
    while(q--)
    {
        ll left,right;
        cin>>left>>right;
        if(GetPreHash(left,right)==GetSufHash(len+1-right,len+1-left))
        {
            cout<<"Is Palindrome"<<endl;
        }
        else
        {
            cout<<"Not Palindrome"<<endl;
        }
    }
    return 0;
}

************ String sum **************
// works in O(n) ..
string BigintSum(string &str1, string &str2)
{
    if((int)str1.size() < (int)str2.size())
        swap(str1, str2) ;
    int len1 = (int)str1.size() ;
    int len2 = (int)str2.size() ;
    int n = len2 ;
    int carry = 0 ;
    string sum ;
    for(int i = len1 - 1, j = len2 - 1 ; i >= 0 ; i--, j--)
    {
        int x ;
        if(n)
        {
            x = str1[i] - '0' + str2[j] - '0' + carry ;
            n-- ;
        }
        else
            x = str1[i] - '0' + carry ;
        carry = x / 10 ;
        x = x % 10 ;
        sum.push_back(x +'0') ;
    }
    if(carry) sum.push_back(carry + '0') ;
    reverse(sum.begin(),sum.end()) ;
    return sum ;
}

******** String Multiplication ***********
//take to string as numbers and returns the product of these two numbers to strings
// On worst case BigintProd take O(n^2) complexity
string BigintProd(string &str1, string &str2)
{
    if((int)str1.size() < (int)str2.size())
        swap(str1, str2) ;
    int len1 = (int)str1.size() ;
    int len2 = (int)str2.size() ;
    int carry = 0, cnt = 1 ;
    string prod, pro ;
    for(int i = len2 - 1 ; i >= 0 ; i--)
    {
        carry = 0 ;
        for(int j = len1 - 1 ; j >=0 ; j--)
        {
            int x = (str2[i] - '0') * (str1[j] - '0') + carry ;
            carry = x / 10 ;
            x = x % 10 ;
            prod.push_back( x+'0') ;
        }
        if(carry) prod.push_back(carry +'0') ;
        reverse(prod.begin(), prod.end()) ;
        if(cnt == 1)
        {
            pro = prod ;
            cnt++ ;
            prod.clear() ;
        }
        else
        {
            pro = BigintSum(pro, prod) ;
            prod.clear() ;
        }
        for(int k = len2 - 1 ; k >= i ; k--)
            prod.push_back('0') ;
    }
    //return "0" if any multiply apply with 0
    if(pro[0] == '0' && pro.size() > 1) pro = "0" ;
    return pro ;
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

************* All possible Permutation **********
set<string> se;
string a;

void permute(int l, int r)
{
    // Base case
    if (l == r)
        se.insert(a);
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(l+1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //string s;
    int m,cnt=0;
    cin>>a;
    permute(0, (int)a.size()-1);
    //cout<<(int)se.size()<<"\n";
    for(string s : se)
    {

        cout<<s<<endl;
    }

    return 0;
}

********** dequeue ********

deque<ll>dq;
dq.push_front();
dq.push_back();
dq.pop_front();
dq.pop_back();


********** all base to decimal ********
long long kick(string s,long long m)
{
    long long ans=0;
    for(char v:s)
    {
        ans*=m;
        ans+=v-'0';
    }
    return ans;
}

********** String to integer *********
string s;
cin>>s;
stringstream x(s);
int n=0;
x>>n;
cout<<n<<endl;

********* sentance to word ********
string str,word;
getline(cin,str);
stringstream s(str);
int count = 0;
while (s >> word)
    cout<<word<<endl;

