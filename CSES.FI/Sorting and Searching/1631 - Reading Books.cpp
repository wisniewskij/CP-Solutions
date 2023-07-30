// github.com/wisniewskij/Code
// cses.fi/problemset/task/1631
// Reading Books
 
 
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
    vector<int> t(n);
    ll sum = 0;
    for(auto &x:t){
        cin>>x;
        sum+=x;
    }
    sort(all(t));
    if(t.back()>sum-t.back()) cout<<2*t.back();
    else cout<<sum;

}