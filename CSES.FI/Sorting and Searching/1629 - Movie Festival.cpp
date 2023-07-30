// github.com/wisniewskij/Code
// cses.fi/problemset/task/1629
// Movie Festival

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
    int n, ans=0;
    cin>>n;
    vector<pair<int,int>> t(n);
    for(auto &[a,b]:t) cin>>a>>b;
    sort(all(t), [](pair<int,int> &x, pair<int,int> &y){return x.nd<y.nd;});
    int b=0;
    for(int i=0;i<n;i++){
        if(t[i].st>=b){
            ans++;
            b=t[i].nd;
        }
    }
    cout<<ans;
}
