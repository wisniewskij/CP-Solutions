// github.com/wisniewskij/Code
// cses.fi/problemset/task/1653
// Elevator Rides
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

pair<int,int> dp[1<<20];

int main(){
    for(int i=1;i<(1<<20);i++) dp[i]={INF, 0};
    dp[0]={1, 0};
    int n, x;
    cin>>n>>x;
    vector<int> w(n);
    for(auto &x:w) cin>>x;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            if(!((1<<j)&i)){
                if(dp[i].nd+w[j]<=x) dp[i|(1<<j)]=min(dp[i|(1<<j)], {dp[i].st, dp[i].nd+w[j]});
                else dp[i|(1<<j)]=min(dp[i|(1<<j)], {dp[i].st+1, w[j]});
            }
    cout<<dp[(1<<n)-1].st;
}

