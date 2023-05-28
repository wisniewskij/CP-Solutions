// github.com/wisniewskij/Code
// cses.fi/problemset/task/1637
// Removing Digits
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000001
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

ll dp[1000001];

// bottom-up

int main(){
    int n;
    cin>>n;
    memset(dp, INF, sizeof(dp));
    dp[0]=0;
    for(int i=0;i<=n;i++)
        for(int j=i;j>0;j/=10)
            dp[i]=min(dp[i], dp[i-j%10]+1);
    cout<<dp[n];
}

// top-down

// ll DP(int n){
//     if(n==0) return 0;
//     if(dp[n]!=-1) return dp[n];
//     ll ans=INF;
//     for(int i=n;i>0;i/=10)
//         if(i%10!=0)
//             ans=min(ans, DP(n-i%10)+1);

//     return dp[n]=ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     memset(dp, -1, sizeof(dp));
//     cout<<DP(n);
// }
 