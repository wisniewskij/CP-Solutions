// github.com/wisniewskij/Code
// cses.fi/problemset/task/1083
// Missing Number

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
    vector<bool> t(n+1);
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        t[a]=1;
    }
    for(int i=1;i<=n;i++)
        if(!t[i]){
            cout<<i;
            return 0;
        }
}
