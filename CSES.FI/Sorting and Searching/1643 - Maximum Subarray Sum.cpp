// github.com/wisniewskij/Code
// cses.fi/problemset/task/1643
// Maximum Subarray Sum

#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll maxi=0, subsum=0;
    for(int i=0;i<n;i++){
        ll tmp;
        cin>>tmp;
        if(i==0) maxi=tmp;
        if(tmp>tmp+subsum) subsum=tmp;
        else subsum+=tmp;
        maxi=max(maxi, subsum);
    }
    cout<<maxi;
}
