#include <bits/stdc++.h>

using namespace std;

int n, d, warning, arr[200001], bucket[201];

int query(int target){
	int cur = 0;
	for(int i = 0; i < 201; ++i){
		if(bucket[i] == 0) continue;
		if(cur <= target && target <= cur+bucket[i]){
			return i;
		}
		cur += bucket[i];
	}
	return 0;
}

int main(){
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	for(int i = 0; i < n; ++i) {
		if(i >= d) {
			if(d&1){
				if(query((d/2)+1)*2 <= arr[i]) ++warning;
			} else {
				if(query((d/2)+1)+query(d/2) <= arr[i]) ++warning;
			}
		}

		++bucket[arr[i]];
		if(i >= d) --bucket[arr[i-d]];
	}
	cout << warning << endl;
	return 0;
}
