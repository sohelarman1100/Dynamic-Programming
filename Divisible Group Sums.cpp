#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
ll ara[205],n,d,m,save[205][15][25];

ll dp(ll ind, ll num,ll sum)
{
    //cout<<ind<<" "<<num<<" "<<sum<<endl;
    if(num==m)
    {
        if(sum%d==0)
        {
            save[ind][num][sum]=1;
            //cout<<1<<endl;
            return 1;
        }
        else
        {
            save[ind][num][sum]=0;
            //cout<<0<<endl;
            return 0;
        }
    }
    if(ind==n)
        return 0;
    if(save[ind][num][sum]!=-1)
        return save[ind][num][sum];
    ll md=((sum%d)+(ara[ind+1]%d))%d;
    if(md<0)
        md+=d;
    ll nibo=dp(ind+1,num+1,md);
    ll nibona=dp(ind+1,num,sum);
    save[ind][num][sum]=nibo+nibona;
    return save[ind][num][sum];
}

int main()
{
    ll i,j,k,l,c,t,q;
    cin>>t;
    for(c=1; c<=t; c++)
    {
        cin>>n>>q;
        for(i=1; i<=n; i++)
            cin>>ara[i];

        cout<<"Case "<<c<<":"<<endl;
        while(q--)
        {
            cin>>d>>m;
            for(i=0; i<=n+2; i++)
                for(j=0; j<=m+2; j++)
                    for(ll j1=0; j1<=22; j1++)
                       save[i][j][j1]=-1;
            k=dp(0ll,0ll,0ll);
            cout<<k<<endl;
        }
        for(i=1; i<=n; i++)
            ara[i]=0;
    }
    return 0;
}
