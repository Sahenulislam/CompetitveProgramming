#include<bits/stdc++.h>
using namespace std;

int linear_sear(int a[],int key,int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i]==key)
            return i;
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
    int m=linear_sear(a,key,n);
    if(m!=-1)
        cout<<"Item is found in index: "<<m+1<<endl;
    else
        cout<<"Item is not found"<<endl;
    return 0;
}
