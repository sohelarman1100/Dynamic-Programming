#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

ll target,vis[51][1005];
ll coin[51],ans=0,take[51];
//ll k=0;
ll cc(ll i, ll amnt)
{
    ll l=0,m,n,j,k=0;
    //cout<<"amnt= "<<amnt<<endl;
    if(i==0)
    {
        //cout<<"!"<<endl;
        if(amnt==target)
        {
            //ans++;
            return 1;
        }
        else
            return 0;
    }
    if(vis[i][amnt]!=-1)
    {
        /*if(vis[i][amnt]==1)
            ans++;*/
        return vis[i][amnt];
    }
    n=(target-amnt)/coin[i];
    n=min(n,take[i]);
    //cout<<"n= "<<n<<"  i="<<i<<endl;
    for(j=0; j<=n; j++)
    {
        //k=max(k,cc(i-1,amnt+(coin[i]*j)));
        k+=cc(i-1,amnt+(coin[i]*j));
        k=k%100000007;
    }
    vis[i][amnt]=k;
    //cout<<"amount= "<<amnt<<"  ret= "<<k<<endl;
    return k;
}

int main()
{
    ll q;
    cin>>q;
    for(ll t=1; t<=q; t++)
    {
        ll i,j,l,m,n;
        for(i=0; i<51; i++)
            for(j=0; j<1005; j++)
                vis[i][j]=-1;
        cin>>n>>target;
        for(i=1; i<=n; i++)
            cin>>coin[i];
        take[0]=coin[0]=0;
        for(i=1; i<=n; i++)
            cin>>take[i];
        ll res=cc(n,0);
        /*if(res==1)
            cout<<"yes target can be made"<<endl;
        else
            cout<<"nO"<<endl;
        cout<<"target can be made for "<<ans<<" times"<<endl;*/
        cout<<"Case "<<t<<": "<<res<<endl;
    }
    return 0;
}
