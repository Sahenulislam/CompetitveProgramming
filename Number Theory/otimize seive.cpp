#include <bits/stdc++.h>
using namespace std;

/*****************Sieve*******************/
// Time Complexity : O(NloglogN)
/*
1. always check mxN.
2. always remeber to call from main() the sieve()-funciton only once.
3. mxN > 1e8 may not supported
*/
const int mxN = 1e8;
bool isp[mxN + 1];
vector <int> prime;
void Sieve()
{
    for (int i = 0; i <= mxN; i++) isp[i] = 0;
    for (int i = 4; i <= mxN; i += 2) isp[i] = 1;
    for (int i = 3; i * i <= mxN; i += 2)
    {
        if (isp[i] == 0)
        {
            for (int j = i * i; j <= mxN; j += i + i)
            {
                isp[j] = 1;
            }
        }
    }
    prime.push_back(2);
    for (int i = 3; i <= mxN; i += 2)
    {
        if (isp[i] == 0) prime.push_back(i);
    }
}
int main()
{

    return 0;
}
