#include <iostream>

const int MAX_N = 100000;

// input
int N, S[MAX_N], T[MAX_N];

// pair array to sort jobs
std::pair<int, int> itv[MAX_N];

int main(){


	std::cin >> N;
	for(int i=0; i<N; i++) std::cin >> S[i];
	
	for(int i=0; i<N; i++) std::cin >> T[i];

	for(int i=0; i<N; i++){
		itv[i].first = T[i];
		itv[i].second = S[i];
	}

	std::sort(itv, itv+N);

	int ans = 0, t = 0;
	for( int i=0; i<N; i++){
		if(t < itv[i].second){
			t = itv[i].first;
			ans++;
		}
	}

	std::cout << ans <<'\n';
}