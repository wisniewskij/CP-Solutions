// github.com/wisniewskij/Code
// cses.fi/problemset/task/1636
// Coin Combinations II
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
    
    dp[0]=1;

    for(int i=0;i<n;i++)
        cin>>coins[i];
    
    for(int j=0;j<n;j++)
        for(int i=0;i+coins[j]<=x;i++){
            if(!dp[i]) continue;
            dp[i+coins[j]]=(dp[i+coins[j]]+dp[i])%mod;
        }    
    
    cout<<dp[x];
}
 