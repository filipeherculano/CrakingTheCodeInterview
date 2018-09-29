#include <bits/stdc++.h>

using namespace std;

long long n, r, arr[100001], res, prefix[100001], sufix[100001];
map<long long,long long> cnt;

int main(){
	cin >> n >> r;
	for(int i = 0; i < n; ++i){
		scanf("%lld", &arr[i]);
		if((arr[i]%r) == 0) prefix[i] = cnt[arr[i]/r];
		++cnt[arr[i]];
	}
	cnt.clear();
	for(int i = n-1; i >= 0; --i){
		sufix[i] = cnt[arr[i]*r];
		++cnt[arr[i]];
	}
	
	for(int i = 0; i < n; ++i) res += (prefix[i])*(sufix[i]);
	cout << res << endl;
	return 0;
}
