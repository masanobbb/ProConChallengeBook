// Dinamic Programming : DP
// Need to initialize array with 0 
// Global var is initialized with 0
#include <iostream>

const int N_MAX = 100, W_MAX = 10000;
int N, W;
int w[N_MAX], v[N_MAX];
int dp[N_MAX+1][W_MAX+1];

int main(){

	std::cin >> N;
	for(int i=0; i<N; i++)
		std::cin >> w[i] >> v[i];
	std::cin >> W;

	for(int i=N-1; i>=0; i--){
		for(int j=0; j<=W; j++){
			if( j < w[i] ){
				dp[i][j] = dp[i+1][j];
			} else{
				dp[i][j] = std::max(dp[i+1][j], dp[i+1][j-w[i]]+v[i]);
			}
		}
	}
	std::cout << dp[0][W] << '\n';
}