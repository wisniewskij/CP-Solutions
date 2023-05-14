// github.com/wisniewskij/Code
// cses.fi/problemset/task/1069
// Repetitions

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
    string s;
    cin>>s;
    int maxi=1;
    int l=1;
    for(unsigned int i=1;i<s.size();i++)
        if(s[i-1]==s[i])
            maxi=max(maxi, ++l);
        else l=1;
    cout<<maxi;
}   

