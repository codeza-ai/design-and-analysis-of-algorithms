//The worst case complexity of the Naive algorithm is O(m(n-m+1)). The time complexity of the KMP algorithm is O(n+m) in the worst case. 
#include <bits/stdc++.h>
using namespace std;

void stringMatching(string& str, string& pat) {
    int n, m;
    n = str.size();
    m = pat.size();
    
    int i, j;
    for(j = 0;j < n- m;j++){
        for(i = 0;i < m;i++) {
            if(str[j+ i] != pat[i])break;
        }
        
        if(i == m)cout<<j<<endl;
    }
}

int main()
{
    string txt = "AABAACAADAABAAABAA";
    string pat = "AABA";
     stringMatching(txt, pat);
    return 0;
}
