#include <bits/stdc++.h>
using namespace std;
void countSort(int a[],int n,int p)
{
    int cont[11]={0},output[n+10];
    for(int i=0; i<n; i++)
    {
        cont[(a[i]/p)%10]++;
    }
    for(int i=1; i<=11; i++)
    {
        cont[i]+=cont[i-1];
    }
    for(int i=n-1; i>=0; i--)
    {
        output[cont[(a[i]/p)%10]-1]=a[i];
        cont[(a[i]/p)%10]--;
    }
    for(int i=0;i<n;i++)
    {
        a[i]=output[i];
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
    for(int p=1; mx/p>0; p*=10)
    {
        countSort(a,n,p);
    }
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}

