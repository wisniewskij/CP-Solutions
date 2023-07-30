// github.com/wisniewskij/Code
// cses.fi/problemset/task/1755
// Palindrome Reorder

#include <bits/stdc++.h>
 
#define ndl '\n'
#define ll long long
#define st first
#define nd second
#define all(x) (x).begin(), (x).end()
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    unordered_map<char, int> ltr;
    string s, s2="";
    int cnt=0;
 
    cin>>s;
    for(char c:s) ltr[c]++;
    char sr=' ';
    for(auto [a,b]:ltr){
        if(b&1){
            cnt++;
            sr=a;
        } 
        if(cnt>1){
            cout<<"NO SOLUTION";
            return 0;
        }
        for(int i=0;i<b/2;i++)
            s2+=a;
    }
    cout<<s2;
    if(sr!=' ') cout<<sr;
    reverse(s2.begin(), s2.end());
    cout<<s2;
}