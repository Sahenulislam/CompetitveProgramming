#include<bits/stdc++.h>
using namespace std;
int lps[1001111];
void KMP_Pre(string pat)
{
    int j=0;
    for(int i=1; i<pat.size(); i++)
    {
        if(pat[i]==pat[j])
        {
            lps[i]=lps[i-1]+1;
            j++;
        }
        else
        {
            j=lps[i-1];
            while(j!=0&&pat[i]!=pat[j])
            {
                j=lps[j-1];
            }
            if(pat[i]==pat[j])
            {
                lps[i]=lps[j]+1;
                j++;
            }
            else
                lps[i]=0;
        }
    }
}
int KMP_Ser(string txt,string pat)
{
    int j=0;
    for(int i=0; i<txt.size(); i++)
    {
        if(txt[i]==pat[j])
            j++;
        else if(txt[i]!=pat[j])
        {
            j=lps[j-1];
            while(j!=0&&txt[i]!=pat[j])
            {
                j=lps[j-1];
            }
            if(txt[i]==pat[j])
                j++;
        }
        if(j==pat.size())
            return 1;
    }
}
int main()
{
    string txt,pat;
    cin>>txt>>pat;
    KMP_Pre(pat);
    if(KMP_Ser(txt,pat)==1)
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
