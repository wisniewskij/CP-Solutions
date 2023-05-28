// github.com/wisniewskij/Code
// cses.fi/problemset/task/1145
// Increasing Subsequence
#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define INF 1000000001
#define st first
#define nd second
#define debug(x) cout << #x << ": " << x << ndl
#define all(x) (x).begin(), (x).end()
#define mod 1000000007
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> tab(n), ssequence;
    for(auto &x:tab) cin>>x;
    for(auto x:tab){
        auto z = lower_bound(all(ssequence), x);
        if(z==ssequence.end())
            ssequence.push_back(x);
        else
            ssequence[z-ssequence.begin()]=x;
    }
    cout<<ssequence.size();
}

