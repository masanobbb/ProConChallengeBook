
#include <iostream>

const int INF = 10000000;
const int N_MAX = 1000;
const int a_MAX = 1000000;

int a[N_MAX];
int N;

int dp[N_MAX];

int main(){

	std::cin >> N;
	for(int i=0; i<N; i++)
		std::cin >> a[i];

	std::fill(dp, dp+N, INF);
	for(int i=0; i<N; i++){
		*std::lower_bound(dp, dp+N, a[i]) = a[i];
	}

	std::cout << std::lower_bound(dp, dp+N, INF) - dp << '\n';

}