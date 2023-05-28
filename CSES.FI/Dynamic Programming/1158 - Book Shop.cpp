// github.com/wisniewskij/Code
// cses.fi/problemset/task/1158
// Book Shop
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

// bottom-up

int main(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> book(n);
    for(int i=0;i<n;i++)
        cin>>book[i].st;
    for(int i=0;i<n;i++)
        cin>>book[i].nd;

    memset(dp, -1, sizeof(dp));
    dp[0]=0;

    for(int j=0;j<n;j++)
        for(int i=x;i-book[j].st>=0;i--)
            if(dp[i-book[j].st]!=-1)
                dp[i]=max(dp[i], dp[i-book[j].st]+book[j].nd);
    
    ll ans = 0;
    for(int i=0;i<=x;i++)
        ans=max(ans, dp[i]);
    cout<<ans;
}
