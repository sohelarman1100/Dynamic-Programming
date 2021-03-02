#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define mod 100000007


int main()
{
    ll t,c;
    ll tot[10005];
    cin>>t;
    for(c=1; c<=t; c++)
    {
        ll i,j,k,l,m,n;
        cin>>n>>k;
        ll val[n+1];
        for(i=1; i<=n; i++)
            cin>>val[i];
        for(i=0; i<=10000; i++)
            tot[i]=0;
        tot[0]=1;
        for(i=1; i<=n; i++)
        {
            for(j=val[i]; j<=k; j++)
            {
                tot[j]+=tot[j-val[i]];
                tot[j]=tot[j]%mod;
            }
        }
        cout<<"Case "<<c<<": "<<tot[k]<<endl;
    }
    return 0;
}
