// github.com/wisniewskij/Code
// cses.fi/problemset/task/1093
// Two Sets II
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

int main(){
    int n;
    cin>>n;
    ll sum=(n*(n+1))/2;

    if(sum&1){
        cout<<0;
        return 0;
    }
    sum>>=1;
    vector<ll> dp(sum+1);
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=sum;j-i>=0;j--)
            dp[j]=(dp[j]+dp[j-i])%mod;
    cout<<(dp[sum]*500000004)%mod; 
    // '500000004' is a modular inverse of 2 because you cant simply divide by it in mod 1e9+7
}

