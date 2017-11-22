#include <cstdio>
#include <iostream>

#define MAX_N 1000000

int par[MAX_N];  // parent
int rank[MAX_N]; // tree depth

// initialize with n elements
void init(int n){
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rank[i] = 0;
	}
}

// find tree root
int find(int x) {
	if (par[x] == x) {
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}

// unite the groups where x and y belong
void unite(int x, int y){

	x = find(x);
	y = find(y);

	if (x == y) return;

	if (rank[x] < rank[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	}
}

// judge if x and y belong to same group
bool same(int x, int y){
	return find(x) == find(y);
}

int main(){



	int N, K;
	std::cin >> N >> K;
	// printf("%d, %d\n", N, K);
	
	// initialize groups
	init(N*3);

	int type, x, y;
	int ans = 0;

	for (int cnt=0; cnt < K; cnt++) {
	
		scanf("%d", &type);
		scanf("%d", &x);
		scanf("%d", &y);
		
		// printf("%d, %d, %d\n", type, x, y);
		x = x-1; y = y-1;

		if (x < 0 || x >= N || y < 0 || y >= N) {
			ans++;
			continue;
		}

		if (type == 1){
			if (same(x, y + N) || same(x, y + 2 * N)) {
				ans++;
			} else {
				unite(x, y);
				unite(x + N, y + N);
				unite(x + 2 * N, y + 2 * N);
			}
		} else {
			if (same(x, y) | same(x, y + 2 * N)) {
				ans++;
			} else {
				unite(x, y + N);
				unite(x + N, y + 2 * N);
				unite(x + 2 * N, y);
			}
		}
	}

	std::cout << ans << std::endl;
	return 0;

}