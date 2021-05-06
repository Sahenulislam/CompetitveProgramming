#include<bits/stdc++.h>
using namespace std;

int binary_sear(int a[],int key,int n)
{
    int low=0,high=n,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]<key)
            low=mid+1;
        else if(a[mid]>key)
            high=mid-1;
    }
    return -1;
}

int main()
{
    int n,key;
    cin>>n;
    int a[n+10];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>key;
    int m=binary_sear(a,key,n);
    if(m!=-1)
        cout<<"Item is found in index: "<<m+1<<endl;
    else
        cout<<"Item is not found"<<endl;
    return 0;
}
