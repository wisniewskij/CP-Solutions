// github.com/wisniewskij/Code
// cses.fi/problemset/task/1623
// Apple Division

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
    ll sum=0;
    cin>>n;
    vector<int> t(n);
    for(auto &x:t){
        cin>>x;
        sum+=x;   
    }
    ll diff = sum;
    for(int i=0;i<(1<<n);i++){
        ll sum2=0;
        for(int j=0; j<n; j++)
            if(i&(1<<j)) sum2+=t[j];
        diff=min(diff, abs(sum-2*sum2));
    }
    cout<<diff;
}
