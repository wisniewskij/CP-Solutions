// github.com/wisniewskij/Code
// cses.fi/problemset/task/1630
// Tasks and Deadlines
 
 
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
    vector<pair<int,int>> t(n);
    for(auto &[x, y]:t) cin>>x>>y;
    sort(all(t), [](pair<int,int> a, pair<int,int> b){if(a.st==b.st) return a.nd>b.nd; return a.st<b.st;});
    ll sum = 0, last=0;
    for(auto [x,y]:t){
        sum+=y-x-last;
        last+=x;
    }
    cout<<sum;

}