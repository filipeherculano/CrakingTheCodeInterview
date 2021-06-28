#include <bits/stdc++.h>

using namespace std;

int q;
string s;

int main(){
	cin >> q;
	for(int i = 0; i < q; ++i){
		cin >> s;
		int res = 0;
		map< string, int > anagrams;
		for(int i = 0; i < (int) s.size(); ++i){
			string cur = "";
			for(int j = i; j < (int) s.size(); ++j){
				cur += s[j];
				sort(cur.begin(), cur.end());
				++anagrams[cur];
			}
		}
		for(auto & par : anagrams)
			res += max(0, par.second * (par.second - 1));
		cout << res/2 << endl;
	}
	return 0;
}
