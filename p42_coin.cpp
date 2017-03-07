#include <iostream>

const int COIN[6] = {1, 5, 10, 50, 100, 500};

int CoinN[6];
int A;


int main(){

	for(int i=0; i<6; i++){
		std::cin >> CoinN[i];
	}
	std::cin >> A;

	// my code
	/*
	int i = 5;
	int ans = 0;
	while(A!=0){
		if(CoinN[i]>0 && (A - COIN[i] >= 0) ){
			A -= COIN[i];
			CoinN[i] = CoinN[i]-1;
			ans++;
			std::cout << A << ',' << COIN[i] << '\n';
		}else i--;
	}

	std::cout << ans << '\n';
	*/

	int ans = 0;
	for( int i=5; i>=0; i--){
		int t = std::min(A / COIN[i], CoinN[i]);	// the num of coin to use
		A -= t * COIN[i];
		ans += t;
	}
	std::cout << ans << '\n';

}