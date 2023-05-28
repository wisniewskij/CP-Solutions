// github.com/wisniewskij/Code
// cses.fi/problemset/task/1639
// Edit Distance
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

ll dp[5001][5001];

int main(){
    string s1,s2;
    cin>>s1>>s2;
    for(int i=1;i<=s1.size();i++)
        dp[i][0]=i;
    for(int i=1;i<=s2.size();i++)
        dp[0][i]=i;

    for(int i=1;i<=s1.size();i++)
        for(int j=1;j<=s2.size();j++)
            dp[i][j]=min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+(s2[j-1]==s1[i-1]?0:1)});
    cout<<dp[s1.size()][s2.size()]<<ndl;
}

