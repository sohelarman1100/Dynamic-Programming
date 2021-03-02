#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define mx 10000000000

ll grid[1005][1005],path[1005][1005],n;
pair<ll,ll> dp[1005][1005];

pair<ll,ll> sln (ll r, ll c)
{
    pair<ll,ll> dwn=mp(mx,mx),rgt=mp(mx,mx);
    ll fst=0,snd=0,num=grid[r][c];

    if(dp[r][c].first!=mx)
        return dp[r][c];

    if(num==0)
    {
        fst=1;
        snd=1;
    }
    while(num%5==0 && num!=0)
    {
        fst++;
        num/=5;
    }
    num=grid[r][c];
    while(num%2==0 && num!=0)
    {
        snd++;
        num/=2;
    }

    if(r==n && c==n)
        return mp(fst,snd);

    if(r==n)
    {
        rgt=sln(r,c+1);
    }
    else if(c==n)
    {
        dwn=sln(r+1,c);
    }
    else
    {
        rgt=sln(r,c+1);
        dwn=sln(r+1,c);
    }
    ll mn1=min(rgt.first,dwn.first);  ///calculation for 5;
    ll mn2=min(rgt.second,dwn.second); ///calulation for 2;
    fst+=mn1;
    snd+=mn2;
    dp[r][c]=mp(fst,snd);
    return dp[r][c];
}

int main()
{
    ll i,j,k,l,m;
    pair<ll,ll>pos=mp(0ll,0ll);
    cin>>n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]==0)
            {
                pos.first=i;
                pos.second=j;
            }
            dp[i][j]=mp(mx,mx);
            path[i][j]=-1;
        }
    }
    pair<ll,ll> ans=sln(1ll,1ll);
    ll res=min(ans.first,ans.second);
    if(pos.first>0 && res>1)
        cout<<1<<endl;
    else
        cout<<res<<endl;
    ll trk;
    if(ans.first<=ans.second)
        trk=5;
    else
        trk=2;
    ll r=1,c=1;
    if(pos.first==0 || res<=1)
    {
        for(i=1; i<=(n*2)-2; i++)
        {
            ll dwn,rgt;
            //cout<<"pair= "<<dp[r][c].first<<" "<<dp[r][c].second<<" "<<dp[r+1][c].first<<" "<<dp[r+1][c].second<<" "<<dp[r][c+1].first<<" "<<dp[r][c+1].second<<endl;
            //cout<<r<<"  "<<c<<endl;
            if(trk==5)
            {
                if(r==n)
                    cout<<'R';
                else if(c==n)
                    cout<<'D';
                else if(dp[r+1][c].first<=dp[r][c+1].first)
                {
                    r=r+1;
                    cout<<'D';
                }
                else
                {
                    c=c+1;
                    cout<<'R';
                }
            }
            else
            {
                if(r==n)
                    cout<<'R';
                else if(c==n)
                    cout<<'D';
                else if(dp[r+1][c].second<=dp[r][c+1].second)
                {
                    r=r+1;
                    cout<<'D';
                }
                else
                {
                    c=c+1;
                    cout<<'R';
                }
            }
        }
    }
    else
    {
        for(i=1; i<pos.second; i++)
            cout<<'R';
        for(i=1; i<n; i++)
            cout<<'D';
        for(i=pos.second; i<n; i++)
            cout<<'R';
    }
    cout<<endl;
    return 0;
}
