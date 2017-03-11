// with Memorize function

#include <iostream>

const int MAX_N=100, MAX_W=10000;
int N, W, w[MAX_N], v[MAX_N];
int dp[MAX_N+1][MAX_W+1];

int rec(int i, int j){
	if(dp[i][j] >= 0){
		return dp[i][j];
	}

	int res;
	if (i==N){
		res = 0;
	} else if( j<w[i] ){
		res = rec(i+1,j);
	} else{
		res = std::max(rec(i+1,j), rec(i+1, j-w[i])+v[i]);
	}

	return dp[i][j] = res;

}

int main(){

	std::cin >> N;
	for(int i=0; i<N; i++)
		std::cin >> w[i] >> v[i];
	std::cin >> W;

	// initialize dp with -1 that means that it's not searched yet
	memset(dp, -1, sizeof(dp));

	std::cout << rec(0,W) <<'\n';
}