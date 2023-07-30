// github.com/wisniewskij/Code
// cses.fi/problemset/task/1092
// Two Sets

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
    int n, sum;
    cin>>n;
    sum = ((1+n)*n)/2;
    if(sum&1){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<ndl;
    vector<int> s1, s2;
    int a = 1, b = n;
    if(n&1){
        s1.push_back(1);
        s1.push_back(n-1);
        s2.push_back(n);
        a = 2; b = n - 2;
    }
    bool z=0;
    for(int i=0;2*i<b-a+1;i++){
        if(z) {
            s1.push_back(a+i);
            s1.push_back(b-i);
        }
        else{
            s2.push_back(a+i);
            s2.push_back(b-i);
        }
        z=!z;
    }
    cout<<s1.size()<<ndl;
    for(auto x: s1) cout<<x<<" ";
    cout<<ndl<<s2.size()<<ndl;
    for(auto x:s2) cout<<x<<" ";
}
