#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ara[93];
ll fib(ll x)
{
    if(x==0)
        return 0;
    if(x==1)
        return 1;
    if(ara[x]!=-1)
        return ara[x];
    else
    {
        ara[x]=fib(x-1)+fib(x-2);
        return ara[x];
    }
}

int main()
{
    memset(ara,-1,sizeof(ara));
    ll p=fib(92);
    ll q;
    cin>>q;
    while(q--)
    {
        ll i,j,k,l,m,n;
        cin>>n;
        cout<<ara[n]<<endl;
    }
}
