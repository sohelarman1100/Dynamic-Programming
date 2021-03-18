#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

ll n;
ll ara[100005],path[100005],dp[100005];
ll mx=0ll,start=0ll;
ll sln(ll pos)
{
    if(pos==n-1)
        return 1ll;
    if(dp[pos]!=-1)
        return dp[pos];
    ll i,j,k=0ll,l,val;
    //cout<<"ara[pos]= "<<ara[pos]<<endl;
    for(i=pos+1; i<n; i++)
    {
        val=sln(i);
        //cout<<"ara[i]= "<<ara[i]<<"  val= "<<val<<endl;
        if(ara[i]>ara[pos])
        {
            if(val>k)
                path[pos]=i;
            k=max(k,val);
        }
        //cout<<"k= "<<k<<endl;
    }
    if(k+1>mx)
    {
        mx=k+1;
        start=pos;
    }
    dp[pos]=k+1;
    return k+1;
}

int main()
{
    ll i,j,k,l,m;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>ara[i];
        dp[i]=path[i]=-1ll;
    }
    sln(0);
    ll ans=0ll;
    for(i=0; i<n; i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;

    while(1)
    {
        cout<<start<<" ";
        start=path[start];
        if(start==-1)
            break;
    }
    cout<<endl;
    return 0;
}
