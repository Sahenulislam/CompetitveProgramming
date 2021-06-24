#include <bits/stdc++.h>
using namespace std;
const int M = 1000;
const int N = 1000;
int dp[M][N];
int nap(int j,int wt[],int val[],int i,int dp[M][N])
{
    if (i<0)
        return 0;
    if (dp[i][j]!= -1)
        return dp[i][j];
    if (wt[i]>j)
    {
        dp[i][j]=nap(j,wt,val,i-1,dp);
        return dp[i][j];
    }
    else
    {
        dp[i][j]=max(nap(j,wt,val,i-1,dp),val[i]+nap(j-wt[i],wt,val,i-1,dp));
        return dp[i][j];
    }
}
int main()
{
    int item,w;
    cin>>item>>w;
    int val[item+10],wt[item+10];
    for(int i=0; i<item; i++)
        cin>>val[i];
    for(int i=0; i<item; i++)
        cin>>wt[i];
    for (int i=0; i<=item; i++)
        for (int j=0; j<w+1; j++)
            dp[i][j]=-1;
    cout<<nap(w,wt,val,item-1,dp);
    return 0;
}

