#include <bits/stdc++.h>

using namespace std;

int p;

int main(){
	cin >> p;
	for(int i = 0; i < p; ++i){
		string a, b;
		bool ok = false;
		set<char> sa;
		cin >> a >> b;
		for(auto &c : a) sa.insert(c);
		for(auto &c : b) ok |= (sa.find(c) != sa.end());
		printf("%s\n", (ok ? "YES":"NO"));
	}
	return 0;
}
