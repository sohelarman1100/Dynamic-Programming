#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define mod 100000007


int main()
{
    ll t,c;
    ll tot[100005];
    cin>>t;
    for(c=1; c<=t; c++)
    {
        ll i,j,k,l,m,n;
        cin>>n>>k;
        ll val[n+1],num_of_coin[n+1],can_make[n+1];
        for(i=1; i<=n; i++)
            cin>>val[i];
        for(i=1; i<=n; i++)
            cin>>num_of_coin[i];
        can_make[0]=0;
        for(i=1; i<=n; i++)
        {
            can_make[i]=min(k,((num_of_coin[i]*val[i])+can_make[i-1]));
            //cout<<can_make[i]<<" ";
        }
        //cout<<endl;
        ll koyta_nilam[k+1];
        memset(koyta_nilam,0,sizeof(koyta_nilam));
        for(i=0; i<=100000; i++)
            tot[i]=0;
        tot[0]=1;
        for(i=1; i<=n; i++)
        {
            for(j=val[i]; j<=can_make[i]; j++)
            {
                if(koyta_nilam[j-val[i]]+1<=num_of_coin[i] && j-val[i]!=0 && tot[j-val[i]]>0 && tot[j]!=1)
                {
                    tot[j]=1;
                    koyta_nilam[j]=koyta_nilam[j-val[i]]+1;
                }
                else if(j-val[i]==0 && tot[j]!=1)
                {
                    tot[j]=1;
                    koyta_nilam[j]=1;
                }
            }
            memset(koyta_nilam,0,sizeof(koyta_nilam));
        }
        ll ans=0;
        for(i=1; i<=k; i++)
        {
            if(tot[i]>0)
            {
                ans++;
                //cout<<i<<" ";
            }
        }
        //cout<<endl;
        cout<<"Case "<<c<<": "<<ans<<endl;
    }
    return 0;
}
/*
1
2 20
5 8
2 1
*/
