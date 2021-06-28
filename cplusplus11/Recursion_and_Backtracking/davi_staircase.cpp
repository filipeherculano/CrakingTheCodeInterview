#include <bits/stdc++.h>

using namespace std;

int main(){
	int s, n;
	scanf("%d", &s);
  	vector<int> res; 
  	res.push_back(1); res.push_back(2); res.push_back(4);
 	for(int i = 3; i < 36; i++) res.push_back(res[i-1] + res[i-2] + res[i-3]);
	while(s--){
		scanf("%d", &n);
		cout << res[n-1] << endl;
	}
	return 0;
}


