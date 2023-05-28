// github.com/wisniewskij/Code
// cses.fi/problemset/task/1634
// Minimizing Coins
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
    for(int i=1;i<=x;i++) dp[i]=INF;
    for(int i=0;i<n;i++)
        cin>>coins[i];
    
    for(int i=1;i<=x;i++)
        for(int j=0;j<n;j++)
            if(i-coins[j]>=0) dp[i]=min(dp[i], dp[i-coins[j]]+1);
    
    cout<<(dp[x]==INF?-1:dp[x]);
}

// top-down

// ll DP(int x, int n){
//     if(x==0) return 0;
//     if(dp[x]!=-1) return dp[x];
//     ll ans = INF;
//     for(int i=0;i<n;i++)
//         if(x-coins[i]>=0)
//             ans=min(ans, DP(x-coins[i], n)+1);

//     return dp[x]=ans;
// }

// int main(){
//     int n,x;
//     cin>>n>>x;
//     for(int i=1;i<=x;i++) dp[i]=-1;
//     for(int i=0;i<n;i++)
//         cin>>coins[i];

//     ll ans = DP(x, n);
    
//     cout<<(ans==INF?-1:ans);
// }

 