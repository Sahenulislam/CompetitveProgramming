#include <bits/stdc++.h>
using namespace std;

int parti(int a[],int lo,int hi)
{
    int pivot=a[hi];
    int i=lo-1;

    for (int j=lo; j<=hi-1; j++)
    {
        if (a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[hi]);
    return i+1;
}

void quickSort(int a[],int lo,int hi)
{
    if (lo<hi)
    {
        int part=parti(a,lo,hi);
        quickSort(a,lo,part-1);
        quickSort(a,part+1,hi);
    }
}


int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0; i<n; i++)
        cin>>a[i];
    quickSort(a,0,n - 1);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    return 0;
}

