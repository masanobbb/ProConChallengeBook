// 最長増加部分列 (LIS : Longest Increasing Subsequence)

#include <iostream>

const int N_MAX = 1000;
const int a_MAX = 1000000;

int N;
int a[N_MAX];
int dp[N_MAX];

int main(){

	std::cin >> N;
	for(int i=0; i<N; i++)
		std::cin >> a[i];

	memset(dp, -1, sizeof(dp));

	int res = 0;

	for(int i=0; i<N; i++){
		dp[i]=1;
		for(int j=0; j<i; j++){
			if( a[j] < a[i] ){
				dp[i] = std::max(dp[i], dp[j]+1);
			}
		}
		res = std::max(res, dp[i]);
	}

	std::cout << res << '\n';
}