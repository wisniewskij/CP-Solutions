// github.com/wisniewskij/Code
// cses.fi/problemset/task/1073
// Towers
 
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
    multiset<int, greater<int>> s;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        auto x = s.lower_bound(tmp);
        if(x==s.begin()) ans++;
        else{
            x--;
            s.erase(x);
        }
        s.insert(tmp);
    }
    cout<<ans;
}