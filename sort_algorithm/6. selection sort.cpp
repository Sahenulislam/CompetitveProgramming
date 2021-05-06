#include <bits/stdc++.h>
using namespace std;


void sertionSort(int a[],int n)
{
    for (int i=1; i<n-1; i++)
    {
        int mn=i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[mn])
                swap(a[j],a[mn]);
        }
    }
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}


int main()
{
    int n;
    cin>>n;
    int a[n+10];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sertionSort(a,n);
    return 0;
}
