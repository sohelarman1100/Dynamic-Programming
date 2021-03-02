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
    ll q;
    cin>>q;
    for(ll c=1; c<=q; c++)
    {
        ll i,j,k,l,m,n,r;
        cin>>n>>k;
        if(k>n)
            cout<<"Case "<<c<<": "<<0<<endl;
        else
        {
            ll ans;
            ans=ncr(n,k);
            for(j=n,l=1; l<=k; l++,j--)
                ans*=j;
            cout<<"Case "<<c<<": "<<ans<<endl;
        }
    }
    return 0;
}
