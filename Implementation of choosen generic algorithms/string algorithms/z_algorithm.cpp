#include <bits/stdc++.h>
using namespace std;

vector<int> build_z_arr(string s) {
    int n = s.size(), x = 0, y = 0;
    vector<int> z(n);
    for(int i=1;i<n;i++) {
        z[i] = max(0, min(z[i-x], y-i+1));
        while(y < n && s[z[i]] == s[i+z[i]]) {
            x = i; z[i]++; y++;
        }
    }
    return z;
}

vector<int> z_algorithm(string s, string p) {
    vector<int> pattern_match_indices;
    vector<int> z_arr = build_z_arr(p + "$" + s);
    for(int i=p.size()+1; i<z_arr.size(); i++) 
        if(z_arr[i] == p.size())
            pattern_match_indices.push_back(i-p.size()-1);
    return pattern_match_indices;
}

