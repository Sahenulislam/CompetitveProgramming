ll isp[mxn+10];
void siv()
{
    for(ll i=2; i<=mxn; i++)isp[i]=i;
    for(ll i=4; i<=mxn; i+=2)isp[i]=2;
    for(ll i=3; i*i<=mxn; i++)
    {
        if(isp[i]==i)
        {
            for(ll j=i*i; j<=mxn; j+=i)
            {
                if(isp[j]==j)
                {
                    isp[j]=i;
                }
            }
        }
    }
}
