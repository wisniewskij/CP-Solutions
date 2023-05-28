// github.com/wisniewskij/Code
// cses.fi/problemset/task/2181
// Counting Tilings
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

ll dp[1002][1<<10];

bool check(int a, int n){
    bool fl=0;
    for(int i=0; i<n; i++){
        if((1<<i)&a){
            if(fl) return 1;
        }
        else
            fl=!fl;
    }
    return fl;
}

// bottom - up

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m; // n - width, m - height

    dp[0][0]=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<(1<<n);j++){
            if(dp[i][j])
                for(int k=0;k<(1<<n);k++)
                    if(!(k&j)&&!check(k|j, n))
                        dp[i+1][k]=(dp[i+1][k]+dp[i][j])%mod;
        }
    
    cout<<dp[m][0];   
}

// top - down

// ll DP(int l, int mask, int width){
//     if(l==0) return mask==0;
//     if(dp[l][mask]!=-1) return dp[l][mask];
    
//     ll ans=0;

//     for(int i=0;i<(1<<width);i++)
//         if(!(i&mask)&&!check(i|mask, width))
//             ans=(ans+DP(l-1, i, width))%mod;
    
//     return dp[l][mask]=ans;
// }

// int main(){
//     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     int n,m;
//     cin>>n>>m; // n - width, m - height

//     for(int i=0;i<=m;i++)
//         for(int j=0;j<(1<<n);j++)
//             dp[i][j]=-1;
    
//     cout<<DP(m, 0, n);
// }

