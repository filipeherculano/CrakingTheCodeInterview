#include <bits/stdc++.h>

using namespace std;

int n, m;
multiset<string> magazine;

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		string aux;
		cin >> aux;
		magazine.insert(aux);
	}
	for(int i = 0; i < m; ++i) {
		string aux;
		cin >> aux;
		auto it = magazine.find(aux);
		if(it != magazine.end()) magazine.erase(it);
		else {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
