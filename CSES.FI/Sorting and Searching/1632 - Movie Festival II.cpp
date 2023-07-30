// github.com/wisniewskij/Code
// cses.fi/problemset/task/1632
// Movie Festival II
 
 
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
    int n,k,ans=0;
    cin>>n>>k;

    vector<pair<int,int>> t(n);
    for(auto &[y,x]:t) cin>>x>>y;
    sort(all(t));

    multiset<int> free;
    
    for(int i=0;i<k;i++) free.insert(0);
 
    for(auto [y,x]:t){
        auto it = free.upper_bound(x);
        if(it!=free.begin()){
            it--;
            free.erase(it);
            free.insert(y);
            ans++;
        }
    }
    cout<<ans;
 
}