// github.com/wisniewskij/Code
// cses.fi/problemset/task/2413
// Counting Towers
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

ll dp1[1000001], dp2[1000001];

int main(){
    int t;
    cin>>t;
    dp1[1]=1; dp2[1]=1;
    for(int i=2;i<=1000000;i++){
        dp1[i]=(dp1[i-1]*2+dp2[i-1])%mod;
        dp2[i]=(dp2[i-1]*4+dp1[i-1])%mod;
    }
    while(t--){
        int n;
        cin>>n;
        cout<<(dp1[n]+dp2[n])%mod<<ndl;
    }
}
