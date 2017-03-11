#include <iostream>

typedef long long ll;


const int MAX_N = 20000;
int N, L[MAX_N];

int main(){

	std::cin >> N;
	for(int i=0; i<N; i++){
		std::cin >> L[i];
	}

	ll ans = 0;

	while( N > 1 ){

		// index of minimum: mii1, second minimum: mii2
		int mii1=0, mii2=1;
		if(L[mii1] > L[mii2]) std::swap(mii1, mii2);

		for(int i=2; i<N; i++){
			if(L[i] < L[mii1]){
				mii2 = mii1;
				mii1 = i;
			}
			else if(L[i] < L[mii2]){
				mii2 = i;
			}
		}

		int t = L[mii1] + L[mii2];
		ans += t;

		if (mii1 == N-1) std::swap(mii1, mii2);
		L[mii1] = t;
		L[mii2] = L[N-1];
		N--;
	}

	std::cout << ans << '\n';

}