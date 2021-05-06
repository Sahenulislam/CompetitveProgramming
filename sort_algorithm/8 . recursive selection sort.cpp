#include<bits/stdc++.h>
using namespace std;

int search_min(int mn,int a[],int low,int high)
{
    if(low==high)
        return mn;
    if(a[low]<a[mn])
        mn=low;
    search_min(mn,a,low+1,high);
}
void selectionsort(int a[],int low,int high)
{
    if(low==high)
        return;
    int min_index=search_min(low,a,low+1,high);
    swap(a[low],a[min_index]);
    selectionsort(a,low+1,high);
}

int main()
{
    int n;
    cin>>n;
    int a[n+10];
    for(int i=0; i<n; i++)
        cin>>a[i];
    selectionsort(a,0,n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}
