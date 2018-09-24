#include <bits/stdc++.h>

using namespace std;

long long n, m, a, b, k, arr[10000001], ans;

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0; i < m; ++i){
		scanf("%d %d %d",&a,&b,&k); --a; --b;
		arr[a] += k;
		arr[b+1] -= k;
	}
	for(int i = 0; i < n; i++){
		if(i) arr[i] += arr[i-1];
		ans = max(ans, arr[i]);
	}
	cout << ans << endl;
	return 0;
}
