#include<bits/stdc++.h>
using namespace std;

void max_heap(int a[],int n,int i)
{
    int lar=i;
    int left=2*i+1;
    int right=2*i+2;

    if (left<n&&a[left]>a[lar])
        lar=left;
    if (right<n&&a[right]>a[lar])
        lar=right;
    if (lar!=i)
    {
        swap(a[i], a[lar]);
        max_heap(a,n,lar);
    }
}

void heapSort(int a[],int n)
{
    for (int i=n/2-1; i>=0; i--)
        max_heap(a,n,i);
    for (int i=n-1; i>=0; i--)
    {
        swap(a[0],a[i]);
        max_heap(a,i,0);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[2222];
    for(int i=0; i<n; i++)
        cin>>a[i];
    heapSort(a,n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}
