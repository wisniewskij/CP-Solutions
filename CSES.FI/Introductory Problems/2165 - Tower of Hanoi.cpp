// github.com/wisniewskij/Code
// cses.fi/problemset/task/2165
// Tower of Hanoi

#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<pair<int,int>> moves;

void toh(int no, int from, int to, int through){
    if(no==1){
        moves.push_back({from, to});
        return;
    }
    toh(no-1, from, through, to);
    moves.push_back({from, to});
    toh(no-1, through, to, from);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    toh(n, 1, 3, 2);
    cout<<moves.size()<<ndl;
    for(auto [a,b]:moves)
        cout<<a<<" "<<b<<ndl;
}
