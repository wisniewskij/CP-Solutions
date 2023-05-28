// github.com/wisniewskij/Code
// cses.fi/problemset/task/1638
// Grid Paths
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000001
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
using namespace std;

ll dp[1001][1001];

// bottom-up

int main(){
    int n;
    cin>>n;
    vector<string> t(n);
    for(int i=0;i<n;i++) cin>>t[i];
    if(t[0][0]!='*') dp[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(t[i][j]!='*')
                dp[i][j]=(dp[i][j]+(i>0?dp[i-1][j]:0)+(j>0?dp[i][j-1]:0))%mod;
    cout<<dp[n-1][n-1];
}

// top-down

// vector<string> t;

// ll DP(int y, int x){
//     if(y==0&&x==0) return t[0][0]=='.';
//     if(t[y][x]=='*') return 0;
//     if(dp[y][x]!=-1) return dp[y][x];
//     ll ans=0;
//     if(y>0)
//         ans=(ans+DP(y-1,x))%mod;
//     if(x>0)
//         ans=(ans+DP(y,x-1))%mod;
//     return dp[y][x]=ans;
// }

// int main(){
//     int n;
//     cin>>n;
//     t.assign(n, "");
//     for(int i=0;i<n;i++) cin>>t[i];
//     for(int i=0;i<n;i++)
//         for(int j=0;j<n;j++)
//             dp[i][j]=-1;
//     cout<<DP(n-1, n-1);
// }