#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int w[n+10],v[n+10];
    string actname;
    vector<pair<int,pair<int,string>>>vec;
    for(int i=0; i<n; i++)
        cin>>w[i];
    for(int i=0; i<n; i++)
        cin>>v[i];
    for(int i=0; i<n; i++)
    {
        cin>>actname;
        vec.push_back({v[i],{w[i],actname}});
    }
    sort(vec.begin(),vec.end());
    int fin=vec[0].first;
    cout<<endl<<"Selected Activity: "<<vec[0].second.second;
    for(int i=1; i<n; i++)
    {
        if(fin<=vec[i].second.first)
        {
            fin=vec[i].first;
            cout<<", "<<vec[i].second.second;
        }
    }
    cout<<endl;
    return 0;
}
