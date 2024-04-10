#include <bits/stdc++.h>

using namespace std;

vector<int> build_lps_arr(string s) {
    int n = s.size(), k = -1;
    vector<int> lps(n+1);
    for(int i=0;i<n;i++) {
        lps[i] = k;
        while(k >= 0 && s[i] != s[k]) {
            k = lps[k];
        }
        k++; // k = (k==-1?0:k+1)
    }
    lps[n] = k;
    return lps;
}

vector<int> kmp(string s, string p) {
    int n = s.size(), m = p.size(), k = 0, i = 0;
    vector<int> lps_arr = build_lps_arr(s), pattern_match_indices;

    while (i+m <= n) {
        if(s[i+k] == p[k]) k++;
        else if(k == 0) i++; //k==0
        else {
            i += k - lps_arr[i+k];
            k = lps_arr[i+k];
        }
        if(k == m) pattern_match_indices.push_back(i);
    }
    return pattern_match_indices;
}