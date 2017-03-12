#include <iostream>

const int N_MAX = 100;
const int K_MAX = 100000;
int a[N_MAX], m[N_MAX];
int N, K;

bool DP[N_MAX+1][K_MAX+1];

int main(){

	std::cin >> N;
	for(int i=0; i<N; i++)
		std::cin >> a[i] >> m[i];
	std::cin >> K;

	DP[0][0] = true;
	for(int i=0; i<N; i++){
		for(int j=0; j<=K; j++){
			for(int k=0; k<=m[i] && k*a[i]<=j; k++){
				DP[i+1][j] |= DP[i][j-k*a[i]];
			}
		}
	}
	if(DP[N][K]) std::cout << "Yes\n";
	else std::cout << "No\n";

}