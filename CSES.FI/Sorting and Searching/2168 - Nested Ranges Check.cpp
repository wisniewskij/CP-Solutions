// github.com/wisniewskij/Code
// cses.fi/problemset/task/2168
// Nested Ranges Check
 
 
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
    vector<tuple<int,int,int>> t(n);
    vector<int> does(n), is(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        t[i]={a,b,i};
    }
    sort(all(t), [](tuple<int,int,int>a, tuple<int,int,int>b){auto [a1,a2,a3]=a; auto [b1,b2,b3]=b; if(a1==b1) return a2>b2; return a1<b1;});
    set<int> s;
    for(auto [a,b,i]:t){
        auto x = s.lower_bound(b);
        if(x!=s.end()) is[i]=1;
        s.insert(b);
    }
    sort(all(t), [](tuple<int,int,int>a, tuple<int,int,int>b){auto [a1,a2,a3]=a; auto [b1,b2,b3]=b; if(a2==b2) return a1>b1; return a2<b2;});

    s.clear();
    for(auto [a,b,i]:t){
        auto x = s.lower_bound(a);
        if(x!=s.end()) does[i]=1;
        s.insert(a);
    }

    for(int i=0;i<n;i++)
        cout<<does[i]<<" ";
    cout<<ndl;
    for(int i=0;i<n;i++)
        cout<<is[i]<<" ";
}