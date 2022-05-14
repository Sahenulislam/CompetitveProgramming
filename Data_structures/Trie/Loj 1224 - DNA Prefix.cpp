#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ans=-1,id;
struct node
{
    int cnt;
    node *next[6];
    node()
    {
        cnt=0;
        for(int i=0; i<5; i++)
            next[i]=NULL;
    }
}*root;

void insert(char *str,int len)
{
    node *cur=root;
    for(int i=0; i<len; i++)
    {
        if(str[i]=='A')id=0;
        else if(str[i]=='C')id=1;
        else if(str[i]=='G')id=2;
        else if(str[i]=='T')id=3;
        if(cur->next[id]==NULL)
            cur->next[id]=new node();
        cur=cur->next[id];
        cur->cnt++;

    }
}

void search(char *str,int len)
{
    node *cur=root;
    for(int i=0; i<len; i++)
    {
        if(str[i]=='A')id=0;
        else if(str[i]=='C')id=1;
        else if(str[i]=='G')id=2;
        else if(str[i]=='T')id=3;
        cur=cur->next[id];
        ans=max(ans,(i+1)*cur->cnt);
    }
}
void del(node *cur)
{
    for(int i=0; i<5; i++)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}
char st[50050][60];
int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        root=new node();

        for(int i=0; i<n; i++)
        {
            cin>>st[i];
            insert(st[i],strlen(st[i]));
        }
        for(int i=0; i<n; i++)
        {
            search(st[i],strlen(st[i]));
        }
        cout<<"Case "<<tt++<<": "<<ans<<endl;
        ans=-1;
        del(root);
    }
    return 0;
}


