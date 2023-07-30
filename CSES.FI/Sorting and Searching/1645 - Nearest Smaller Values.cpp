// github.com/wisniewskij/Code
// cses.fi/problemset/task/1645
// Nearest Smaller Values

 
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
    int n;
    cin>>n;
    vector<pair<int,int>> t;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        while(t.size() && t.back().st>=tmp) t.pop_back();
        cout<<(t.size()?t.back().nd:0)<<" ";
        t.push_back({tmp, i});
    }
    
}