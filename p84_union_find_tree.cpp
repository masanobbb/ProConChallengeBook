#include <cstdio>
using namespace std;

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