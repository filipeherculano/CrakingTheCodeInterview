#include <bits/stdc++.h>
#define maxn 5001

using namespace std;

string s1,s2;
int pd[maxn][maxn], n;

int main(){
    memset(pd,0,sizeof pd);
    cin >> s1 >> s2;
    n = (int) s1.size();
    pd[0][0] = (s1[0] == s2[0] ? 1:0);
    for(int i = 1; i < n; ++i) pd[0][i] = max((s1[0] == s2[i] ? 1:0), pd[0][i-1]);
    for(int i = 1; i < n; ++i) pd[i][0] = max((s1[i] == s2[0] ? 1:0), pd[i-1][0]);
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < n; ++j){
            pd[i][j] = max(pd[i][j], pd[i][j-1]);
            pd[i][j] = max(pd[i][j], pd[i-1][j]);
            pd[i][j] = max(pd[i][j], pd[i-1][j-1] + (s1[i] == s2[j] ? 1:0));
        }
    }
    cout << pd[n-1][n-1] << endl;
    return 0;
}
