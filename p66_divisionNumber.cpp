#include <iostream>

const int M_MAX = 1000, N_MAX = 1000;

int M;
int n, m;

int dp[M_MAX+1][N_MAX+1];


int main(){

	std::cin >> n >> m >> M;
	dp[0][0] = 1;
	for(int i=1; i<=m; i++){
		for(int j=0; j<=n; j++){
			if( j-i >= 0)
				dp[i][j] = (dp[i][j-i] + dp[i-1][j]) % M;
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	std::cout << dp[m][n] << '\n';

}