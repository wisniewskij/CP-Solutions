// github.com/wisniewskij/Code
// cses.fi/problemset/task/1674
// Subordinates

#include <bits/stdc++.h>

#define ndl '\n'
#define ll long long
#define INF 1000000007
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<vector<int>> G;
vector<int> sub;
int dfs(int n){
    int sum = 0;
    for (auto v : G[n])
        sum += dfs(v);
    sub[n] = sum;
    return sum + 1;
}

int main(){
    int n;
    cin >> n;
    G.assign(n + 1, vector<int>());
    sub.assign(n + 1, 0);
    for (int i = 2; i <= n; i++){
        int tmp;
        cin >> tmp;
        G[tmp].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
        cout << sub[i] << " ";
}