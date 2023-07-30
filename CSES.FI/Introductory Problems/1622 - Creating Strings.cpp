// github.com/wisniewskij/Code
// cses.fi/problemset/task/1622
// Creating Strings

#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, s2;
    cin>>s;
    sort(all(s));
    vector<string> tab={s};
    int ile = 1;
    s2=s;
    
    while (true){
        next_permutation(s.begin(), s.end());
        if(s==s2) break;
        ile++;
        tab.push_back(s);
    }
    cout<<ile<<ndl;
    for(auto x:tab)
        cout<<x<<ndl;
}