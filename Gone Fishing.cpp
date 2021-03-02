#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
ll n,h,ex[30][200],decrs[30],pass_time[30],start;
pair<ll,ll> dp[30][200];

pair<ll,ll> solve(ll ind, ll time)
{
    ll i,j,l,k1=0;
    pair<ll,ll> rec;
    ll pos;
    if(ind==n+1)
    {
        pair<ll,ll> p=mp(0ll,0ll);
        return p;
    }
    if(dp[ind][time].first !=-1)
        return dp[ind][time];

    for(i=0; i<=time; i++)
    {
        ll tm=time-pass_time[ind+1]-i;
        if(tm<0)
            tm=0;
        pair<ll,ll> rec=solve(ind+1,tm);
        if(ex[ind][i]+rec.first>=k1)
        {
            k1=ex[ind][i]+rec.first;
            pos=i;
        }
    }
    dp[ind][time].first=k1;
    dp[ind][time].second=pos;
    return dp[ind][time];
}

int main()
{
    ll t,c;
    cin>>t;
    for(c=1; c<=t; c++)
    {
        ll i,j,k,l;
        cin>>n>>h;
        h=((60*h)/5);
        for(i=0; i<=n; i++)
            for(j=0; j<=h; j++)
                dp[i][j].first= -1ll;
        for(i=1; i<=n; i++)
            cin>>ex[i][1];
        for(i=1; i<=n; i++)
            cin>>decrs[i];

        for(i=1; i<=n; i++)
        {
            for(j=2; j<=h; j++)
            {
                k=ex[i][1]-((j-1)*decrs[i]);
                if(k<0)
                    k=0;
                ex[i][j]=ex[i][j-1]+k;
            }
        }
        for(i=2; i<=n; i++)
            cin>>pass_time[i];

        pair<ll,ll> p=solve(1ll,h);
        ll ans=p.first;
        cout<<"Case "<<c<<":"<<endl;
        start=p.second;
        ll tot=start;
        for(i=1; i<=n; i++)
        {
            if(i!=n)
                cout<<start*5<<", ";
            else
                cout<<start*5<<endl;
            ll indx=h-tot-pass_time[i+1];
            //cout<<"ind= "<<indx<<endl;
            if(indx<0)
                indx=0;
            start=dp[i+1][indx].second;
            tot+=(start+pass_time[i+1]);
        }
        cout<<"Number of fish expected: "<<ans<<endl;

        for(i=0; i<=n+2; i++)
        {
            decrs[i]=pass_time[i]=0;
            for(j=0; j<=h+2; j++)
                ex[i][j]=0;
        }
    }
    return 0;
}

/*
2
2 1
50 30
4 3
3

3 2
15 50 30
3 4 3
2 3

1
3 1
3 7 5
1 2 2
1 2
*/
