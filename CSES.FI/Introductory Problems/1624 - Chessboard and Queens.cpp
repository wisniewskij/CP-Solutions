// github.com/wisniewskij/Code
// cses.fi/problemset/task/1624
// Chessboard and Queens

#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<bool> vertical(8, 0), diag1(15, 0), diag2(15, 0);

ll queens(int x, vector<string> &s){
    if(x==8) return 1;
    ll ans = 0;
    for(int i=0;i<8;i++)
        if(s[x][i]=='.' && !vertical[i] && !diag1[i-x+7] && !diag2[i+x]){
            vertical[i]=1;
            diag1[i-x+7]=1;
            diag2[i+x]=1;
            ans+=queens(x+1, s);
            vertical[i]=0;
            diag1[i-x+7]=0;
            diag2[i+x]=0;
        }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<string> s(8);
    for(int i=0;i<8;i++) cin>>s[i];
    cout<<queens(0, s);
}
