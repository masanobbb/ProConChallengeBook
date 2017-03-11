#include <iostream>

const int N_MAX = 100, W_MAX = 10000;
int w[N_MAX], v[N_MAX];
int N,W;

int DP[N_MAX][W_MAX];

int main(){

	std::cin >> N;
	for(int i=0; i<N; i++)
		std::cin >> w[i] >> v[i];
	std::cin >> W;

	for(int i=0; i<N; i++){
		for(int j=0; j<=W; j++){
			if( j < w[i] ){
				DP[i+1][j] = DP[i][j]; 
			} else {
				DP[i+1][j] = std::max(DP[i][j], DP[i+1][j-w[i]] + v[i]);
			}
		}
	}
	std::cout << DP[N][W] << '\n';

}