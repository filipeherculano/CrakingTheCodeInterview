#include <bits/stdc++.h>

using namespace std;

int n;
vector< pair<int,string> > v[1001];

int main(){
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> v[i].second >> v[i].first, v[i].first *= -1;
	sort(v, v+n);
	for(int i = 0; i < n; ++i) cout << v[i].second << " " << v[i].first*(-1) << endl;
	return 0;
}
