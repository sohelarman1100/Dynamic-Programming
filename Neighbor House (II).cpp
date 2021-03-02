#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


ll n,num_of_soap[1005];
pair<ll,ll>dp[1005];

pair<ll,ll> res(ll pos)
{
    ll i,j;
    pair<ll,ll> p,k;
    k.first=-1;
    k.second=0;
    if(pos+2>n || pos==n)
    {
        if(pos==n)
            p.second=1ll;
        else
            p.second=0ll;
        p.first=num_of_soap[pos];
        return p;
    }
    if(dp[pos].first!=-1)
        return dp[pos];
    for(i=pos+2; i<=n; i++)
    {
        pair<ll,ll> x=res(i);
        if(k.first < x.first)
           k=x;
    }
    k.first+=num_of_soap[pos];
    dp[pos]=k;
    return dp[pos];
}

int main()
{
    ll q,c;
    cin>>q;
    for(c=1; c<=q; c++)
    {
        ll i,j;
        cin>>n;
        for(i=0; i<=n+2; i++)
        {
            dp[i].first=-1;
            dp[i].second=0;
        }
        for(i=1; i<=n; i++)
            cin>>num_of_soap[i];

        pair<ll,ll>p1,p2;

        p1=res(1ll);
        p2=res(2);
        cout<<p1.first<<endl;
        if(p1.second==1)
            p1.first=p1.first-min(num_of_soap[1],num_of_soap[n]);

        ll ans=max(p1.first,p2.first);
        cout<<"Case "<<c<<": "<<ans<<endl;
    }
    return 0;
}
