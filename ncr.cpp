#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

ll ara[32][32];

ll ncr(ll n,ll r)
{
    if(n==r || r==0)
    {
        ara[n][r]=1;
        return 1;
    }
    if(r==1)
    {
        ara[n][r]=n;
        return n;
    }
    if(ara[n][r]>0)
        return ara[n][r];
    else
    {
        ara[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
        return ara[n][r];
    }
}

int main()
{
    ll i,j,k,l,m,n,r;
    cin>>n>>r;
    ncr(n,r);
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=i && j<=r; j++)
        {
            cout<<"ara["<<i<<"]"<<"["<<j<<"] = "<<ara[i][j]<<endl;
        }
    }
    return 0;
}
