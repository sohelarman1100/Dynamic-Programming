#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define  ms(a,b)      memset(a,b,sizeof(a))
#define  gcd(a, b)    __gcd(a,b)
#define  lcm(a, b)    ((a)*(b)/gcd(a,b))
#define  PI            2*acos(0.0)
#define  min3(a,b,c)    min(a,min(b,c))
#define  min4(a,b,c,d)  min(d,min(a,min(b,c)))
#define  max3(a,b,c)    max(a,max(b,c))
#define  max4(a,b,c,d)  max(d,max(a,max(b,c)))
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl

int ara[2005][10],n,row=-1;
int val[2005][12][2005];
int trk=-1,point[2005];

int dp(int r,int c, int baki)
{
    int k=-1,i;
    if(r==n)
    {
        //cout<<"r="<<r<<"  c="<<c<<"  baki="<<baki<<" point="<<point[0]<<endl;
        if(baki==0)
            return c;
        else
            return -1;
    }
    if(val[r][c][baki]!=-2)
        return val[r][c][baki];
    for(i=9; i>=0; i--)
    {
        if(ara[r+1][i]<=baki)
            k= max(k,dp(r+1,i,baki-ara[r+1][i]));
    }
    //cout<<"r="<<r<<"  c="<<c<<"  k="<<k<<" point="<<point[0]<<endl;
    val[r][c][baki]=k;
    if(k==-1)
        return -1;
    else
    {
        if(r+1==n)
            trk=0;
        if(point[r]==-1)
            point[r]=k;
        return c;
    }
}

int main()
{
    int i,j,l,m,k;
    vector<string>vec;
    vec.pb("1110111");
    vec.pb("0010010");
    vec.pb("1011101");
    vec.pb("1011011");
    vec.pb("0111010");
    vec.pb("1101011");
    vec.pb("1101111");
    vec.pb("1010010");
    vec.pb("1111111");
    vec.pb("1111011");
    cin>>n>>k;
    for(i=0; i<=n; i++)
    {
        point[i]=-1;
        for(j=0; j<=9; j++)
        {
            for(l=0; l<=2001; l++)
                val[i][j][l]=-2;
        }
    }
    string s;
    int num,cnt;
    for(i=1; i<=n; i++)
    {
        cin>>s;
        num=-1;
        for(j=0; j<=9; j++)
        {
            cnt=0;
            for(ll j1=0; j1<7; j1++)
            {
                if(vec[j][j1]==s[j1])
                    cnt++;
            }
            if(cnt==7)
            {
                num=j;
                break;
            }
        }
        for(j=0; j<=9; j++)
        {
            if(j==num)
                ara[i][j]=0;
            else
            {
                cnt=0;
                for(ll j1=0; j1<7; j1++)
                {
                    if(vec[j][j1]!=s[j1] && vec[j][j1]=='1')
                        cnt++;
                    if(vec[j][j1]!=s[j1] && s[j1]=='1')
                    {
                        cnt=2005;
                        break;
                    }
                }
                ara[i][j]=cnt;
            }
        }
    }
    int ans=dp(0,0,k);
    if(trk==-1)
    {
        cout<<-1<<endl;
        return 0;
    }
    for(i=0; i<n; i++)
        cout<<point[i];
    cout<<endl;
    return 0;
}
