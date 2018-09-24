#include <bits/stdc++.h>

using namespace std;

int t,n,v[100001],w[100001];

int main(){
    scanf("%d",&t);
    while(t--){
        int res = 0;
        scanf("%d",&n);
        for(int i = 0; i < n; ++i) scanf("%d",&v[i]), w[i] = i+1;
        for(int i = 0; i < n; ++i){
        	for(int j = 1; j < 3; ++j){
                if(i-j >= 0 && w[i] == v[i-j]){
                    res += j;
                    swap(w[i], w[i-1]);
                    if(j == 2) swap(w[i-2], w[i-1]);
                    i-=j;
                    break;
                }
            }
        }
        bool ok = true;
        for(int i = 0; i < n; ++i) ok &= (w[i] == v[i]);
        if(ok) cout << res << endl;
        else puts("Too chaotic");
    }
    return 0;
}

