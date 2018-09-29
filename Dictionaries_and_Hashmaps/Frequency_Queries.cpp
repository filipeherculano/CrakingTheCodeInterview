#include <bits/stdc++.h>

using namespace std;

int q, x;
map<int,int> freq, freq_rev;

int main(){
	cin >> q;
	for(int i = 0; i < q; ++i){
		int op;
		scanf("%d %d", &op, &x);
		if(op == 1) {
			if(freq[x]) --freq_rev[freq[x]];
			++freq[x];
			++freq_rev[freq[x]];
		} else if(op == 2 && freq[x]) {
			--freq_rev[freq[x]];
			--freq[x];
			if(freq[x]) ++freq_rev[freq[x]];
		} else if(op == 3) printf("%s\n", (freq_rev[x] ? "1":"0"));
	}
	return 0;
}
