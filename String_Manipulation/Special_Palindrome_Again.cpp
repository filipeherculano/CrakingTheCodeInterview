#include <bits/stdc++.h>
#define maxn 1000001

using namespace std;

long long n, l[maxn], r[maxn], res;
string s;

int main(){
    cin >> n >> s;
    for(int i = 1; i < n; ++i) l[i] = (s[i-1] == s[i] ? 1+l[i-1]:0);
    for(int i = n-2; i >= 0; --i) r[i] = (s[i+1] == s[i] ? 1+r[i+1]:0);    
    for(int i = 1; i < n-1; ++i) if(s[i-1] == s[i+1] && s[i] != s[i+1]) {
        res += min(l[i-1], r[i+1]) + 1;
    }
    int i = 0;
    while(i < n){
        int sz = (r[i]+1), N = sz, a1 = 1, aN = sz;
        res += ((a1+aN)*N)/2;
        i += r[i] + 1;
    }
    cout << res << endl;
    return 0;
}


