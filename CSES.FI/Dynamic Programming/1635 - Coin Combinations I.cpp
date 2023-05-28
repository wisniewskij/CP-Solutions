// github.com/wisniewskij/Code
// cses.fi/problemset/task/1635
// Coin Combinations I
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF (ll)(1e17)
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
using namespace std;

ll dp[1000001], coins[100];

// bottom-up

int main(){
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=x;i++) dp[i]=0;
    dp[0]=1;

    for(int i=0;i<n;i++)
        cin>>coins[i];
    
    for(int i=0;i<x;i++)
        for(int j=0;j<n;j++)
            if(i+coins[j]<=x) dp[i+coins[j]]=(dp[i+coins[j]]+dp[i])%mod;
    
    cout<<dp[x];
}

// top-down

// ll DP(int x, int n){
//     if(x==0) return 1;
//     if(dp[x]!=-1) return dp[x];
//     ll ans = 0;
//     for(int i=0;i<n;i++)
//         if(x-coins[i]>=0)
//             ans=(ans+DP(x-coins[i], n))%mod;

//     return dp[x]=ans;
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     memset(dp, -1, sizeof(dp));
//     for(int i=0;i<n;i++)
//         cin>>coins[i];

//     cout<<DP(x, n);
// }

 