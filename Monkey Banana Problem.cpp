#include<bits/stdc++.h>
using namespace std;
#define ll long long

int kola[205][105],ate[205][105];
int n;

ll banana(int x, int i)
{
    int mx1=0,mx2=0;
    if(x==(n*2)-1)
    {
        kola[x][i]=ate[x][i];
        return kola[x][i];
    }
    if(kola[x][i]!=-1)
        return kola[x][i];
    if(x<n)
    {
        mx1=banana(x+1,i);
        mx2=banana(x+1,i+1);
        kola[x][i]=ate[x][i]+max(mx1,mx2);
    }
    else
    {
        if(i==1)
        {
            mx1=banana(x+1,i);
        }
        else if(i==n+n-x)
        {
            mx1=banana(x+1,i-1);
        }
        else
        {
            mx1=banana(x+1,i);
            mx2=banana(x+1,i-1);
        }
        kola[x][i]=ate[x][i]+max(mx1,mx2);
    }
    return kola[x][i];
}

int main()
{
    int q;
    cin>>q;
    for(int c=1; c<=q; c++)
    {
        int i,j,k=1,l,m;
        cin>>n;
        for(i=1; i<=(n*2)-1; i++)
        {
            if(i<=n)
                for(j=1; j<=i; j++)
                    kola[i][j]=-1;
            else
            {
                for(j=1; j<=n-k; j++)
                    kola[i][j]=-1;
                k++;
            }
        }
        k=1;
        for(i=1; i<=(n*2)-1; i++)
        {
            if(i<=n)
                for(j=1; j<=i; j++)
                    cin>>ate[i][j];
            else
            {
                for(j=1; j<=n-k; j++)
                    cin>>ate[i][j];
                k++;
            }
        }
        k=banana(1ll,1ll);
        cout<<"Case "<<c<<": "<<k<<endl;
    }
    return 0;
}
