// github.com/wisniewskij/Code
// cses.fi/problemset/task/1091
// Concert Tickets

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
    int n, m;
    cin>>n>>m;
    vector<int> t(m);
    multiset<int> s;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        s.insert(tmp);
    }
    for(auto &x:t) cin>>x;

    for(int i=0;i<m;i++){
        auto z = s.lower_bound(t[i]);
        if(s.size()==0||(z==s.begin()&&*z>t[i])) cout<<-1<<ndl;
        else{
            if(z==s.end()||*z>t[i]) z--;
            cout<<*z<<ndl;
            s.erase(z);
        }
    }
    

}
