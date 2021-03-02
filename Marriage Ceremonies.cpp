#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

ll prio[1<<21],ara[20][20],n,mx;

ll st(ll mask, ll pos)
{
    return (mask | (1<<(pos-1)));
}
ll chk(ll mask, ll pos)
{
    return (mask & (1<<(pos-1)));
}

ll dp(ll mask, ll r, ll c)
{
    ll i,j,k=0;
    if(r==n)
    {
        prio[mask]=ara[r][c];
        return prio[mask];
    }
    if(prio[mask]!=-1)
        return ara[r][c]+prio[mask];
    for(i=1; i<=n; i++)
    {
        if(chk(mask,i)==0)
        {
            ll nwmask=st(mask,i);
            prio[mask]=max(prio[mask],(dp(nwmask,r+1,i)));
        }
    }
    return ara[r][c]+prio[mask];
}

int main()
{
    ll q;
    cin>>q;
    for(ll c=1; c<=q; c++)
    {
        ll i,j,k,l,m;
        cin>>n;
        for(i=0; i<(1<<n+1); i++)
            prio[i]=-1;
        ara[0][1]=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                cin>>ara[i][j];
        }
        ll ans=dp(0ll, 0ll, 1ll);
        cout<<"Case "<<c<<": "<<ans<<endl;
    }
    return 0;
}
