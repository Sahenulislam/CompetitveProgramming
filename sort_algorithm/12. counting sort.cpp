#include <bits/stdc++.h>
using namespace std;
int cont[10000],output[1000];
void countSort(int a[],int n,int mx)
{
    memset(cont,0,sizeof(cont));
    for(int i=0; i<n; i++)
    {
        cont[a[i]]++;
    }
    for(int i=1; i<=mx; i++)
    {
        cont[i]+=cont[i-1];
    }
    for(int i=n-1; i>=0; i--)
    {
        output[cont[a[i]]-1]=a[i];
        cont[a[i]]--;
    }
}

int main()
{
    int n;
    int mx=INT_MIN;
    cin>>n;
    int a[n+10];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    countSort(a,n,mx);
    for(int i=0; i<n; i++)
        cout<<output[i]<<" ";

    return 0;
}

