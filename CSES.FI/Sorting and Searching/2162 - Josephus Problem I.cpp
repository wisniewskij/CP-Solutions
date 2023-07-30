// github.com/wisniewskij/Code
// cses.fi/problemset/task/2162
// Josephus Problem I

 
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
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    auto x = s.begin();
    while(s.size()){
        x++;
        if(x==s.end()) x=s.begin();
        auto y = x++;
        if(x==s.end()) x=s.begin();
        cout<<*y<<" ";
        s.erase(y);
    }
}