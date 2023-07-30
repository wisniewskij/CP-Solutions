// github.com/wisniewskij/Code
// cses.fi/problemset/task/1163
// Traffic Lights

 
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
    int x, n;
    cin>>x>>n;
    set<pair<int,int>> seg;
    multiset<int> len;
    seg.insert({x, 0});
    len.insert(x);
    while(n--){
        int tmp, a, b;
        cin>>tmp;
        auto s = seg.lower_bound({tmp, 0});
        a=(*s).nd;
        b=(*s).st;
        auto l = len.find(b-a);
        len.erase(l);
        seg.erase(s);
        seg.insert({tmp, a});
        seg.insert({b, tmp});
        len.insert(tmp-a);
        len.insert(b-tmp);
        l=len.end();
        l--;
        cout<<*l<<ndl;
    }
}