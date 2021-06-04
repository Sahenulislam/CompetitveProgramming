#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int w[n+10],v[n+10];
    vector<pair<double,int>>vec;
    for(int i=0; i<n; i++)
        cin>>w[i];
    for(int i=0; i<n; i++)
        cin>>v[i];
    for(int i=0; i<n; i++)
    {
        vec.push_back({(double)v[i]/w[i],w[i]});
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    double profit=0;
    for(int i=0;i<n;i++)
    {
        if(m>=vec[i].second)
        {
            profit+=vec[i].first*vec[i].second;
            m-=vec[i].second;
        }
        else if(m<vec[i].second)
        {
            profit+=vec[i].first*m;
            m=0;
        }
        if(m<=0)
            break;
    }
    cout<<"Profit= "<<profit<<endl;
    return 0;
}
