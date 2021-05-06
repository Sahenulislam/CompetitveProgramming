#include<bits/stdc++.h>
using namespace std;

void search_fa(int mn,int a[],int low)
{
    if(low==-1||a[mn]>=a[low])
        return;
    else
        swap(a[mn],a[low]);
    search_fa(mn-1,a,low-1);
}

void insertionsort(int a[],int low,int high)
{
    if(low==high)
        return;
    search_fa(low,a,low-1);
    insertionsort(a,low+1,high);
}

int main()
{
    int n;
    cin>>n;
    int a[n+10];
    for(int i=0; i<n; i++)
        cin>>a[i];
    insertionsort(a,0,n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}
