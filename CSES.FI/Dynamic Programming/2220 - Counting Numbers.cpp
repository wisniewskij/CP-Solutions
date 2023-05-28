// github.com/wisniewskij/Code
// cses.fi/problemset/task/2220
// Counting Numbers
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

ll dp[20][10][2][2];
vector<int> number;

ll DP(int idx, int prv, bool below_upper_bound, bool not_leading_zero){
    if(idx==number.size()) return 1;
    if(dp[idx][prv][below_upper_bound][not_leading_zero]!=-1) return dp[idx][prv][below_upper_bound][not_leading_zero];
    ll sum = 0, lim = 9;
    if(!below_upper_bound) lim=number[idx];
    for(int i=0;i<=lim;i++){
        if(!(i==prv)||(i==0 && !not_leading_zero))
            sum += DP(idx+1, i, below_upper_bound|(i<lim?1:0), not_leading_zero|(i!=0?1:0));
    }
    return dp[idx][prv][below_upper_bound][not_leading_zero]=sum;
}

ll run_dp(ll a){
    if(a<0) return 0;
    memset(dp, -1, sizeof(dp));
    number.clear();
    for(ll i=a;i>0;i/=10) number.push_back(i%10);
    reverse(all(number));
    return DP(0, 0, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b;
    cin>>a>>b;
    cout<<run_dp(b)-run_dp(a-1);
}

