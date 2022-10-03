********** Dis Join Set Union ************
const ll mxn=1e5;
ll parent[mxn+3],siz[mxn+3],com,mx=1;
void make_set(ll n)
{
    for(ll i=1; i<=n; i++)
    {
        parent[i]=i;
        siz[i]=1;
    }
}
ll FIND(ll x)
{
    if(x==parent[x])
        return x;
    return parent[x]=FIND(parent[x]);
}
void UNION(ll u,ll v)
{
    u=FIND(u);
    v=FIND(v);
    if(uu!=vv)
    {
        com--;
        if(siz[uu]<siz[vv])
            swap(uu,vv);
        siz[uu]+=siz[vv];
        mx=max(siz[uu],mx);
        parent[vv]=uu;
    }
}


****************** trie ******************

struct node
{
    bool endmark;
    node *next[27];
    node()
    {
        endmark=false;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }
}*root;

void insert(char *str,int len)
{
    node *cur=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(cur->next[id]==NULL)
            cur->next[id]=new node();
        cur=cur->next[id];
    }
    cur->endmark=true;
}

bool search(char *str,int len)
{
    node *cur=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(cur->next[id]==NULL)
            return false;
        cur=cur->next[id];
    }
    return cur->endmark;
}

void del(node *cur)
{
    for(int i=0; i<26; i++)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}

***************** Segment Tree **************

const ll mxn=1e5;
ll a[mxn+3],seg[4*mxn];
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        seg[cur]=a[left];
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    seg[cur]=seg[cur*2]+seg[cur*2+1];
}
void update(ll cur,ll left,ll right,ll pos,ll val)
{
    if(pos<left||pos>right)return;
    if(pos<=left&&pos>=right)
    {
        seg[cur]+=val;
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,pos,val);
    update(cur*2+1,mid+1,right,pos,val);
    seg[cur]=seg[cur*2]+seg[cur*2+1];
}
ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(r<left||l>right)return 0;
    if(l<=left&&r>=right)return seg[cur];
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return (x+y);
}



************** Segment Tree Lazy ****************

const ll mx=1e5;
ll seg[mx*4],lazy[mx*4],a[mx+4];
void build(ll cur,ll left,ll right)
{
    if(left==right)
    {
        seg[cur]=a[left];
        return;
    }
    ll mid=(left+right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    seg[cur]=seg[cur*2]+seg[cur*2+1];
}
void PushDown(ll cur,ll left,ll right)
{
    if(lazy[cur]%2)
    {
        seg[cur]=(right+1-left)-seg[cur];
        if(left!=right)
        {
            lazy[cur*2]+=lazy[cur];
            lazy[cur*2+1]+=lazy[cur];
        }
    }
    lazy[cur]=0;
}
void update(ll cur,ll left,ll right,ll l,ll r)
{
    if(lazy[cur]%2)PushDown(cur,left,right);
    if(l>right||left>r)return;
    if(l<=left&&r>=right)
    {
        lazy[cur]+=1;
        PushDown(cur,left,right);
        return;
    }
    ll mid=(left+right)/2;
    update(cur*2,left,mid,l,r);
    update(cur*2+1,mid+1,right,l,r);
    seg[cur]=seg[cur*2]+seg[cur*2+1];
}
ll query(ll cur,ll left,ll right,ll l,ll r)
{
    if(lazy[cur]%2)PushDown(cur,left,right);
    if(l>right||left>r)return 0;
    if(l<=left&&r>=right)
    {
        PushDown(cur,left,right);
        return seg[cur];
    }
    ll mid=(left+right)/2;
    ll x=query(cur*2,left,mid,l,r);
    ll y=query(cur*2+1,mid+1,right,l,r);
    return (x+y);
}


******** Segment tree with Binary search **********

int main()
{
    for(ll i=0; i<n; i++)
    {
        ll left=0;
        ll right=n-1;
        while(left<=right)
        {
            ll mid=(left+right)/2;
            ll ans=query(1,0,n-1,0,mid);
            if(ans>=pos[i])
            {
                right=mid-1;
            }
            else left=mid+1;
        }
        cout<<a[left]<<" ";
        update(1,0,n-1,left,0);
    }
}


****************** LCA ****************

const ll mxn=2e5+2;
vector<ll>graph[mxn];
ll Level[mxn],Parent[mxn];
ll ST[mxn][70];
void DFS(ll u,ll p)
{
    for(auto v:graph[u])
    {
        if(v!=p)
        {
            Parent[v]=u;
            Level[v]=Level[u]+1;
            DFS(v,u);
        }
    }
}

void SparseTable(ll n)
{
    memset(ST,-1,sizeof(ST));
    for(ll i=1; i<=n; i++)
        ST[i][0]=Parent[i];
    for(ll j=1; (1<<j)<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            if(ST[i][j-1]!=-1)
                ST[i][j]=ST[ST[i][j-1]][j-1];
        }
    }
}

ll LCA(ll u,ll L) // kth parent
{
    ll log;
    if(Level[u]<L)
        return -1;
    while(L>0)
    {
        log=log2(L);
        u=ST[u][log];
        L-=(1<<log);
    }
    return u;
}

ll LCA(ll u,ll v) //lowest common ancestor
{
    if(Level[u]<Level[v])
        swap(u,v);
    ll log=log2(Level[u]);
    for(ll j=log; j>=0; j--)
    {
        if(Level[u]-(1<<j)>=Level[v])
            u=ST[u][j];
    }
    if(u==v)return u;
    for(ll j=log; j>=0; j--)
    {
        if(ST[u][j]!=ST[v][j])
        {
            u=ST[u][j];
            v=ST[v][j];
        }
    }
    return Parent[u];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q,u,v;
    cin>>n>>q;
    Parent[n]=-1;
    Level[n]=0;
    for(ll i=0; i<n-1; i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(n,-1);
    SparseTable(n);
    while(q--)
    {
        cin>>u>>v;
        ll lca=LCA(u,v);
        cout<<Level[u]+Level[v]-(2*Level[lca])<<endl;
        // distance 2node
    }
    return 0;
}



*********** Squre Root Decomposition ***********

const ll mxn=1e5;
ll a[mxn+5],freq[mxn+5]= {0},ans[mxn+5],sqt,cnt=0;
struct query
{
    ll idx,l,r;
};
query Q[mxn+5];

ll cmp(query & a, query &b)
{
    ll x=a.l/sqt;
    ll y=b.l/sqt;
    if(x!=y)
        return a.l<b.l;
    else
        return a.r<b.r;
};

void add(ll pos)
{
    freq[a[pos]]++;
    if(freq[a[pos]]==1)cnt++;
}

void removed(ll pos)
{
    freq[a[pos]]--;
    if(freq[a[pos]]==0)cnt--;
}

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n,q,x,y;
        cin>>n>>q;
        sqt=sqrt(n);
        for(ll i=0; i<n; i++)
            cin>>a[i];
        for(ll i=0; i<q; i++)
        {
            cin>>x>>y;
            Q[i].l=x;
            Q[i].r=y;
            Q[i].idx=i;
        }
        sort(Q,Q+q,cmp);
        ll left=0,right=-1;
        for(ll i=0; i<q; i++)
        {
            ll L=Q[i].l;
            ll R=Q[i].r;
            L--,R--;
            while(left<L)
            {
                removed(left);
                left++;
            }
            while(left>L)
            {
                left--;
                add(left);
            }
            while(right<R)
            {
                right++;
                add(right);
            }
            while(right>R)
            {
                removed(right);
                right--;
            }
            ans[Q[i].idx]=cnt;
        }
        cout<<"Case "<<tt++<<":"<<endl;
        for(ll i=0; i<q; i++)
        {
            cout<<ans[i]<<endl;
        }
        memset(a,0,sizeof(a));
        memset(freq,0,sizeof(a));
        memset(ans,0,sizeof(a));
        cnt=0;
    }
    return 0;
}


********** PBDS-Policy Based Data Structure ************

#include <bits/stdc++.h>
using namespace std ;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including
//tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree <
int,
null_type,
less < int >,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set ;
// *st.find_by_order(k) ; kth element
//  st.order_of_key(k) ; number of element less than k
// Other operations are same as set.
