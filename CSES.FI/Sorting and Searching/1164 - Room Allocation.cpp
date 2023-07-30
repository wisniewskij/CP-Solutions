// github.com/wisniewskij/Code
// cses.fi/problemset/task/1164
// Room Allocation
 
 
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
    int n, ans=0;
    cin>>n;
    vector<tuple<int,int,int>> t(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        t[i]={a,b,i};
    } 
    sort(all(t));

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> idx(n);

    for(auto [x,y,i]:t){
        if(q.empty()||q.top().st>=x){
            ans++;
            q.push({y, ans});
            idx[i]=ans;
        }
        else{
            auto p = q.top();
            q.pop();
            q.push({y, p.nd});
            idx[i]=p.nd;
        }
    }
    cout<<ans<<ndl;
    for(int i=0;i<n;i++) cout<<idx[i]<<" ";

}