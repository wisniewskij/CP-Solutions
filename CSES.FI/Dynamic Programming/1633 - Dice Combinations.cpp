// github.com/wisniewskij/Code
// cses.fi/problemset/task/1633
// Dice Combinations
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

ll dp[1000001];

// bottom-up

int main(){
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=0;i<n;i++)
        if(dp[i])
            for(int j=1;j<=6&&i+j<=n;j++)
                dp[i+j]=(dp[i+j]+dp[i])%mod;
    cout<<dp[n];
}

// top-down

// ll DP(int n){
//     if(n==0) return 1;
//     if(dp[n]!=-1) return dp[n];
//     ll sum = 0;
//     for(int i=1;i<=6&&n-i>=0;i++)
//         sum=(sum+DP(n-i))%mod;
//     return dp[n]=sum;
// }

// int main(){
//     int n;
//     cin>>n;
//     memset(dp, -1, sizeof(dp));
//     cout<<DP(n);
// }

 