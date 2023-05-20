// github.com/wisniewskij/Code
// cses.fi/problemset/task/1193
// Labyrinth
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
    int n,m;
    cin>>n>>m;
    vector<string> t(n);
    for(int i=0;i<n;i++) cin>>t[i];

    pair<int,int> A,B;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(t[i][j]=='A')
                A={i,j};
            else if(t[i][j]=='B')
                B={i,j};
        }
    int x[]={1,0,-1,0}, y[]={0,1,0,-1};
    string d="RDLU";
    vector<vector<int>> par(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    par[A.st][A.nd]=-2;
    q.push(A);
    while (!q.empty()){
        pair<int,int> v=q.front();
        q.pop();
        for(int i=0;i<4;i++)
            if(v.st+y[i]<n&&v.st+y[i]>=0&&v.nd+x[i]<m&&v.nd+x[i]>=0&&t[v.st+y[i]][v.nd+x[i]]!='#'&&par[v.st+y[i]][v.nd+x[i]]==-1){
                par[v.st+y[i]][v.nd+x[i]]=i;
                q.push({v.st+y[i],v.nd+x[i]});
            }
    }
    if(par[B.st][B.nd]==-1) cout<<"NO";
    else{
        cout<<"YES"<<ndl;
        vector<int> stack;
        pair<int,int> tmp=B;
        while(tmp!=A){
            stack.push_back(par[tmp.st][tmp.nd]);
            tmp={tmp.st-y[par[tmp.st][tmp.nd]], tmp.nd-x[par[tmp.st][tmp.nd]]};
        }
        cout<<stack.size()<<ndl;
        for(int i=stack.size()-1;i>=0;i--)
            cout<<d[stack[i]];
    }
    
}