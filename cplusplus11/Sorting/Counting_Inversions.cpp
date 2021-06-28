#include <bits/stdc++.h>

using namespace std;

int d, n, arr[10000001];

long long merge_sort(int L, int R){
	if(L == R) return 0;

	int mid = (L+R)/2, i = L, j = mid+1;
	long long inv = merge_sort(L,mid) + merge_sort(mid+1,R);

	int temp_arr[R-L+1], cur = 0;
	while(i <= mid && j <= R){
		if(arr[i] > arr[j]){
			temp_arr[cur++] = arr[j++];
			inv += mid-i+1;
		} else temp_arr[cur++] = arr[i++];
	}
	while(i <= mid) temp_arr[cur++] = arr[i++];
	while(j <= R) temp_arr[cur++] = arr[j++];
	for(int it = L; it <= R; ++it) arr[it] = temp_arr[it-L];

	return inv;
}

int main(){
	scanf("%d",&d);
	while(d--){
		scanf("%d",&n);
		for(int i = 0; i < n; ++i) scanf("%d",&arr[i]);
		cout << merge_sort(0,n-1) << endl; 
	}
	return 0;
}
