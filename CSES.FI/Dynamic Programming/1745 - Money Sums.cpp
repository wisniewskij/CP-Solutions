// github.com/wisniewskij/Code
// cses.fi/problemset/task/1745
// Money Sums
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

ll dp[100001];

int main(){
    int n;
    cin>>n;
    vector<int> coins(n);
    for(auto &x:coins) cin>>x;
    dp[0]=1;
    for(auto x:coins)
        for(int i=100000;i-x>=0;i--)
            if(dp[i-x]) dp[i]=1;
    

    int sum=0;
    for(int i=1;i<=100000; i++) if(dp[i]) sum++;
    cout<<sum<<ndl;
    for(int i=1;i<=100000; i++) if(dp[i]) cout<<i<<" ";
}

