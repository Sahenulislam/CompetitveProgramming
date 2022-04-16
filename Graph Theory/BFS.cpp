
// Direct Algorithm
#include<bits/stdc++.h>
using namespace std;
vector<int>g[10010],path[10010];
int visit[10010],level[10010];
void BFS(int u,int des)
{
    int a,b,i,flag=0;
    visit[u]=1;
    //level[u]=0;
    queue<int>que;
    que.push(u);
    while(!que.empty())
    {
        a=que.front();
        for(i=0; i<g[a].size(); i++)
        {
            b=g[a][i];
            if(visit[b]==0)
            {
                visit[b]=1;
                //level[b]=level[a]+1;
                path[b].push_back(a);
                if(b==des)
                {
                    flag=1;
                    break;
                }
                que.push(b);
            }
        }
        if(flag==1)
            break;
        que.pop();
    }
    vector<int>ve;
    ve.push_back(b);
    int x=b;
    while(x!=0)
    {
        ve.push_back(path[x][0]);
        x=path[x][0];
    }
    for(int i=ve.size()-1; i>=0; i--)
        cout<<ve[i]<<" ";
    cout<<endl;
}

int main()
{
    int n,i,a,b,m;
    while(cin>>n>>m)
    {
        for(int i=0; i<=n+10; i++)
        {
            g[i].clear();
            path[i].clear();
            visit[i]=0;
            //level[i]=0;
        }
        for(i=1; i<=m; i++)
        {
            cin>>a>>b;
            g[a].push_back(b);
        }
        BFS(0,n-1);
    }
    return 0;
}
