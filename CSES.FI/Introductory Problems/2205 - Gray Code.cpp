// github.com/wisniewskij/Code
// cses.fi/problemset/task/2205
// Gray Code

#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

string to_str(int x, int n){
    string ans = "";
    for(int i=0;i<n;i++)
        if((1<<i)&x)
            ans+="1";
        else ans+="0";
    reverse(all(ans));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    cout<<to_str(0,n)<<ndl;
    for(int i=1;i<(1<<n);i++)
        cout<<to_str(i^(i>>1), n)<<ndl;
}
