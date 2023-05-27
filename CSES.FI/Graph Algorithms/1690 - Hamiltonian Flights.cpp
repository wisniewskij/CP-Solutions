// github.com/wisniewskij/Code
// cses.fi/problemset/task/1690
// Hamiltonian Flights
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
 
ll dp[1<<20][20];
vector<vector<int>> G;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    G.assign(n, vector<int>());
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        G[a-1].push_back(b-1);
    }
    dp[1][0]=1;
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(!(i&(1<<j))||!dp[i][j]) continue;
            for(auto x:G[j])
                if(!((1<<x)&i))
                    dp[i|(1<<x)][x]=(dp[i|(1<<x)][x]+dp[i][j])%mod;
        }
    }
    cout<<dp[(1<<n)-1][n-1];
    
}   