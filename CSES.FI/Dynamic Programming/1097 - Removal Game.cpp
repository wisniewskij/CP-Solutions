// github.com/wisniewskij/Code
// cses.fi/problemset/task/1097
// Removal Game
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

ll dp[5000][5000];

int main(){
    int n;
    cin>>n;
    vector<int> tab(n);
    for(auto &x: tab) cin>>x;
    for(int i=n-1;i>=0;i--)
        for(int j=i;j<n;j++){
            if(i==j) dp[i][j]=tab[i];
            else{
                dp[i][j]=max(tab[i]-dp[i+1][j], tab[j]-dp[i][j-1]);
            }
        }
    
    ll sum=0;
    for(auto x:tab) sum+=x;
    
    cout<<(sum-dp[0][n-1])/2+dp[0][n-1];

}

