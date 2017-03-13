#include <iostream>

const int N_MAX = 1000, M_MAX = 1000;

int n,m;
int a[N_MAX];
int M;

int dp[N_MAX+1][M_MAX+1];

int main(){

	std::cin >> n >> m;
	for(int i=0; i<n; i++)
		std::cin >> a[i];
	std::cin >> M;

	for(int i=0; i<n; i++){
		dp[i][0] = 1;
		for(int j=0; j<=m; j++){
			if(j-1-a[i]>=0)
				dp[i+1][j] = dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]];
			else
				dp[i+1][j] = dp[i+1][j-1] + dp[i][j];
		}
	}

	std::cout << dp[n][m] << '\n';
}
