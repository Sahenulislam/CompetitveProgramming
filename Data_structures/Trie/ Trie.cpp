#include <bits/stdc++.h>
using namespace std;
#define ll long long


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

int main()
{
    ll t,tt=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        root=new node();
        char str[50];
        for(int i=0; i<n; i++)
        {
            cin>>str;
            insert(str,strlen(str));
        }
        ll q;
        cin>>q;
        while(q--)
        {
            cin>>str;
            if(search(str,strlen(str)))
                cout<<"Found"<<endl;
            else
                cout<<"Not Found"<<endl;
        }
        del(root);
    }
    return 0;
}

