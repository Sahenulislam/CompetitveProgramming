#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int a[n+10];
    for(int i=0;i<n;i++)
        cin>>a[i];
    insertionSort(a,n);
    return 0;
}
