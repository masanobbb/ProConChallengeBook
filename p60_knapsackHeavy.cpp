#include <iostream>

const int INF = 10000000;
const int N_MAX = 100, V_MAX=100;
int N, W;
int DP[N_MAX][N_MAX*V_MAX+1];
int w[N_MAX], v[N_MAX];

int main(){

	std::cin >> N;
	for(int i=0; i<N; i++)
		std::cin >> w[i] >> v[i];
	std::cin >> W;

	std::fill(DP[0], DP[0]+N_MAX*V_MAX + 1, INF);
	DP[0][0] = 0;

	for(int i=0; i<N; i++){
		for(int j=0; j<= N_MAX*V_MAX; j++){
			if (j < v[i])
			{
				DP[i+1][j] = DP[i][j];	
			}else {
				DP[i+1][j] = std::min(DP[i][j], DP[i][j-v[i]]+w[i]);
			}

		}
	}

	int res = 0;
	for(int i=0; i<=N_MAX*V_MAX; i++) if(DP[N][i] <= W) res = i;
	std::cout << res << '\n';
}