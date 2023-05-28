// github.com/wisniewskij/Code
// cses.fi/problemset/task/1746
// Array Description
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

ll dp[100002][102];

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> t(n+1);
    for(int i=1;i<=n;i++)
        cin>>t[i];

    if(t[1]) dp[1][t[1]]=1;
    else for(int i=1;i<=m;i++) dp[1][i]=1;
    
    for(int i=2;i<=n;i++){
        if(t[i]) dp[i][t[i]]=(dp[i-1][t[i]]+dp[i-1][t[i]-1]+dp[i-1][t[i]+1])%mod;
        else for(int j=1;j<=m;j++) dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j+1])%mod;
    }
    
    if(t[n]) cout<<dp[n][t[n]];
    else{
        ll ans=0;
        for(int i=1;i<=m;i++) ans=(ans+dp[n][i])%mod;
        cout<<ans;
    }
}
