#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool flag;
struct node
{
    int endmark;
    node *next[27];
    node()
    {
        endmark=0;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }
}*root;

void insert(char *str,int len)
{
    node *cur=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'0';
        if(cur->next[id]==NULL)
            cur->next[id]=new node();
        cur=cur->next[id];
    }
    cur->endmark++;
}

void search(char *str,int len)
{
    node *cur=root;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'0';
        cur=cur->next[id];
    }
    if(cur->endmark>1)
        flag=true;
    for(int i=0; i<26; i++)
    {
        if(cur->next[i])
            flag=true;
    }
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
        char str[10050][30];
        for(int i=0; i<n; i++)
        {
            cin>>str[i];
            insert(str[i],strlen(str[i]));
        }
        for(int i=0; i<n; i++)
        {
            flag=false;
            search(str[i],strlen(str[i]));
            if(flag==true)
                break;
        }
        if(flag==true)
            cout<<"Case "<<tt++<<": NO"<<endl;
        else
            cout<<"Case "<<tt++<<": YES"<<endl;
        del(root);
    }
    return 0;
}


