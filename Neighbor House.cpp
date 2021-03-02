#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pre_cst[22][4],col_cost[22][4],n;
ll min_cost(ll x,ll i)
{
    ll c1,c2,c3;
    if(x==n)
    {
        pre_cst[x][i]=col_cost[x][i];
        return pre_cst[n][i];
    }
    if(pre_cst[x][i]!=-1)
        return pre_cst[x][i];
    c1=min_cost(x+1,1);
    c2=min_cost(x+1,2);
    c3=min_cost(x+1,3);
    if(i==1)
        pre_cst[x][i]=col_cost[x][i]+min(c2,c3);
    else if(i==2)
        pre_cst[x][i]=col_cost[x][i]+min(c1,c3);
    else
        pre_cst[x][i]=col_cost[x][i]+min(c1,c2);

    return pre_cst[x][i];
}

int main()
{
    ll q;
    cin>>q;
    for(ll a=1; a<=q; a++)
    {
        memset(pre_cst,-1,sizeof(pre_cst));
        ll i,j,k,l,m;
        cin>>n;
        for(i=1; i<=n; i++)
            for(j=1; j<=3; j++)
                cin>>col_cost[i][j];
        ll ans=min_cost(1ll,1ll);
        k=col_cost[1][2]+min(pre_cst[2][1],pre_cst[2][3]);
        l=col_cost[1][3]+min(pre_cst[2][1],pre_cst[2][2]);
        ans=min(ans,min(k,l));
        cout<<"Case "<<a<<": "<<ans<<endl;
    }
    return 0;
}
