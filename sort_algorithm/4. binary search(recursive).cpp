#include<bits/stdc++.h>
using namespace std;

int binary_sear(int a[],int key,int low,int high)
{
    int mid=(low+high)/2;
    if(low>high)
        return -1;
    else if(a[mid]==key)
        return mid;
    else if(a[mid]<key)
        binary_sear(a,key,mid+1,high);
    else if(a[mid]>key)
        binary_sear(a,key,low,mid-1);
}

int main()
{
    int n,key;
    cin>>n;
    int a[n+10];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>key;
    int m=binary_sear(a,key,0,n);
    if(m!=-1)
        cout<<"Item is found in index: "<<m+1<<endl;
    else
        cout<<"Item is not found"<<endl;
    return 0;
}
