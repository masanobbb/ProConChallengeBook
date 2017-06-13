
#include <iostream>

const int K_MAX = 100000;
const int N_MAX = 100;

int a[N_MAX], m[N_MAX];
int N,K;

int dp[K_MAX+1];

int main(){

	std::cin >> N;
	for(int i=0; i<N; i++)
		std::cin >> a[i];
	for(int i=0; i<N; i++)
		std::cin >> m[i];
	std::cin >> K;

	memset(dp, -1, sizeof(dp));

	dp[0] = 0;

	for(int i=0; i<N; i++){
		for(int j=0; j<=K; j++){
			if( dp[j]>=0 ){
				dp[j] = m[i];
			}
			else if( j < a[i] || dp[j-a[i]]<=0){
				dp[j] = -1;
			}
			else{
				dp[j] = dp[j-a[i]] - 1; 
			}
		}
	}

	if (dp[K] >= 0) std::cout << "Yes\n";
	else std::cout << "No\n";
	

}