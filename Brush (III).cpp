#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

vector<pair<ll,ll> >vec;
ll n,w,k;

ll save[105][105];///pos,mov
ll dp(ll pos, ll mov)
{
    ll val1=0,val2=0;
    if(pos>n-1 || mov==0)
    {
        //cout<<pos<<"  "<<mov<<"  "<<val1<<"  "<<val2<<endl;
        return 0;
    }
    if(pos==n-1)
    {
        //cout<<pos<<"  "<<mov<<"  "<<val1<<"  "<<val2<<endl;
        return vec[pos].first;
    }
    if(save[pos][mov]!=-1)
    {
        //cout<<pos<<"  "<<mov<<"  "<<val1<<"  "<<val2<<endl;
        return save[pos][mov];
    }
    val1=vec[pos].first + dp(vec[pos].second,mov-1);
    //cout<<pos<<" fi  "<<mov<<"  "<<val1<<"  "<<val2<<endl;
    val2=dp(pos+1,mov);
    //cout<<pos<<"  "<<mov<<"  "<<val1<<"  "<<val2<<endl;
    save[pos][mov]=max(val1,val2);
    return save[pos][mov];
}

int main()
{
    ll q,p;
    cin>>q;
    for(p=1; p<=q; p++)
    {
        vec.clear();
        ll i,j,l,m,x,y;
        cin>>n>>w>>k;

        for(i=0; i<=n+2; i++)
            for(j=0; j<=k+2; j++)
                save[i][j]=-1;

        ll ara[n],ara1[n];
        for(i=0; i<n; i++)
        {
            cin>>x>>y;
            ara[i]=y;
        }
        sort(ara,ara+n);
        for(i=0; i<n; i++)
        {
            x=lower_bound(ara,ara+n,ara[i])-ara;
            y=upper_bound(ara,ara+n,ara[i]+w)-ara;
            ll dirt=y-x;
            //cout<<dirt<<"  "<<x<<"  "<<y<<endl;
            vec.pb(mp(dirt,y));
        }
        //cout<<"dp"<<endl;
        ll ans=dp(0,k);
        cout<<"Case "<<p<<": "<<ans<<endl;
    }
    return 0;
}

/*
1
4 3 1
-1 -2
-1 -5
-1 2
-1 -9
*/
